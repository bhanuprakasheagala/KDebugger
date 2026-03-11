#include <libkdebugger/dwarf.hpp>

const std::unordered_map<std::uint64_t, kdebugger::abbrev> & kdebugger::dwarf::get_abbrev_table(std::size_t offset) {
	if(!m_AbbrevTables.count(offset))
		m_AbbrevTables.emplace(offset, parse_abbrev_table(*m_Elf, offset));

	return m_AbbrevTables.at(offset);
}

// will refactor this later
std::unordered_map<std::uint64_t, kdebugger::abbrev> parse_abbrev_table(const kdebugger::elf & obj, std::size_t size) {
	cusor cur(obj.get_section_contents(".debug_abbrev"));
	cur += offset;

	std::unordered_map<std::uint64_t, kdebugger::abbrev> table;
	std::uint64_t code = 0;

	do {
		// parse entries
		code = cur.uleb128();
		auto tag = cur.uleb128();
		auto has_children = static_cast<bool>(cur.u8());

		std::vector<kdebugger::attr_spec> attr_specs;
		std::uint64_t attr = 0;
		do {
			attr = cur.uleb128();
			auto form = cur.uleb128();
			
			if(attr != 0)
				attr_specs.push_back(kdebugger::attr_spec {attr, form});

		} while(attr != 0);

		if(code != 0)
			table.emplace(code, kdebugger::abbrev {code, tag, has_children, std::move(attr_specs)});
		
	} while(code != 0);

	return table;
}

const std::unordered_map<std::uint64_t, kdebugger::abbrev> & kdebugger::compile_unit::abbrev_table() const {
	returb=n m_Parent->get_abbrev_table(m_AbbrevOffset);
}
