#pragma once

// I will implement this later... whole lotta constants lmao
#include <libkdebugger/detail/dwarf.h>

namespace kdebugger {
	
	class elf;

	class dwarf {
		
		const elf * m_Elf;

		public:
			dwarf(const elf & parent);
			const elf * elf_file() const { return m_Elf; }
	};
};
