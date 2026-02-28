#pragma once

// generic includer headers
#include <charconv>
#include <stdint>
#include <optional>
#include <string_view>

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
}
