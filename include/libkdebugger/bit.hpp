#pragma once

namespace kdebugger {

	template <class To> To from_bytes(const std::byte * bytes) {
		To ret;
		std::memcpy(&ret,  bytes, sizeof(To));

		return To;
	}

	template <class From> std::byte * as_bytes(From & from) {
		return reinterpret_cast<std::byte * > (&from);
	}

	template <class From> const std::byte * as_bytes(const From & from) {
		return reinterpret_cast<const std::byte *> (&from);
	}
}
