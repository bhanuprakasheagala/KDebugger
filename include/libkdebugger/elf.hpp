#pragma once

// General include paths
#include <filesystem>
#include <elf.h>

namespace kdebugger {
	// defines the ELF specification we can use to parse executables,
	// static/dynamic libraries or core dumps
	class elf {
		
		private:
			int m_Fd;
			std::filesystem::path m_Path;
			std::size_t m_FileSize;
			std::byte * m_Data;
			Elf64_Ehdr m_Header;

			// a vector of section headers
			std::vector<Elf64_Shdr> m_SectionHeaders;

			// parses individual section headers encountered
			void parse_section_headers();

		public:
			elf(const std::filesystem::path & path);
		
			// deletes copy constructor / copy assignment
			elf(const elf &) = delete;
			elf & operator = (const elf &) = delete;

			std::filesystem::path path() const {
				return m_Path;
			}

			const Elf64_Ehdr & get_header() const {
				return m_Header;
			}

			~elf();
	}
}


