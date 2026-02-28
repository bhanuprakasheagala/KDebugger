#pragma once

// generic includer headers
#include <charconv>
#include <stdint>
#include <optional>
#include <string_view>
#include <array>
#include <cstddef>

namespace kdebugger {

	template <class T>
	std::optional<T> to_integral(std::string_view sv, int base = 10) {
		auto begin = sv.begin();

		if(base == 16 && sv.size() > 1 && begin[0] == '0' && begin[1] == 'x')
			begin += 2;

		T ret;
		auto result = std::from_chars(begin, sv.end(), ret, base);
		if(result.ptr != sv.end())
			return std::nullopt;

		return ret;
	}

	template <class F>
	std::optional<F> to_float(std::string_view sv) {
		F ret;
		auto result = std::from_chars(sv.begin(), sv.end(), ret);

		if(result.ptr != sv.end())
			return std::nullopt;

		return ret;
	}

	template <std::size_t N>
	auto parse_vector(std::string_view text) {
		auto invalid = [] { 
			kdebugger::error::send("Invalid format!\n");
		};

		std::array<std::byte, N> bytes;
		const char* ch = text.data();

		if(*ch++ != '[')
			invalid();

		for(auto i {0}; i < N - 1; ++i) {
			bytes[i] = to_integral<std::byte> ({c, 4}, 16).value();
			ch += 4;

			if(*c++ != ',')
				invalid();
		}
	}
}
