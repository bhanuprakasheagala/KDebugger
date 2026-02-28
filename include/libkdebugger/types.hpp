#pragma once

#include <array>
#include <cstddef>
#include <cstdint>

namespace kdebugger {

	using byte64 = std::array<std::byte, 8>;
	using byte128 = std::array<std::byte, 16>;
	
	class virt_addr {
		
		private:
			std::uint64_t m_Addr {0};

		public:
			virt_addr() = default;

			explicit virt_addr(std::uint64_t addr) : m_Addr {addr} {}

			std::uint64_t addr() const {
				return m_Addr;
			}

			// operatpr overloads
			virt_addr operator + (std::uint64_t offset) const {
				return virt_addr(m_Addr + offset);
			}

			virt_addr operator - (std::uint64_t offset) const {
				return virt_addr(m_Addr - offset);
			}

			virt_addr & operator += (std::uint64_t offset) {
				m_Addr += offset;
				return *this;
			}

			virt_addr & operator -= (std::uint64_t offset) {
				m_Addr -= offset;
				return *this;
			}
			
			// can replace these eventually with <=>
			bool operator == (const virt_addr & rhs) const noexcept {
				return m_Addr == rhs.m_Addr;
			}

			bool operator != (const virt_addr & rhs) const noexcept {
				return m_Addr != rhs.m_Addr;
			}

			bool operator < (const virt_addr & rhs) const noexcept {
				return m_Addr < rhs.m_Addr;
			}	

			bool operator <= (const virt_addr & rhs) const noexcept {
				return m_Addr <= rhs.m_Addr;
			}

			bool operator > (const virt_addr & rhs) const noexcept {
				return m_Addr > rhs.m_Addr;
			}

			bool operator >= (const virt_addr & rhs) const noexcept {
				return m_Addr >= rhs.m_Addr;
			}
	};
}
