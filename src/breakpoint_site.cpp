#include <libkdebugger/breakpoint_site.hpp>

namespace {
	
	auto get_next_id() {
		static kdebugger::breakpoint_site::id_type id = 0;
		return ++id;
	}
}

kdebugger::breakpoint_site::breakpoint_site(process & proc, virt_addr address)
	: m_Process {&proc}, m_Address {address}, m_isEnabled {false}, m_SavedData {} {
	m_Id = get_next_id();
}
