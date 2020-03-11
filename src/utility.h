#ifndef CODEPOINT_ITERATOR_UTILITY_H_
#define CODEPOINT_ITERATOR_UTILITY_H_

#include <cstdint>

namespace UTF8 {
namespace dtl {

enum class CodeUnitType : std::uint8_t {
	NON_ASCII    = 0b10000000,
	HEAD_TWO     = 0b01000000,
	HEAD_THREE   = 0b00100000,
	HEAD_FOUR    = 0b00010000,
	HEAD         = HEAD_TWO,
};

enum class CodePoint : std::uint8_t {
	BODY         = 0b00111111,
	HEAD_TWO     = 0b00011111,
	HEAD_THREE   = 0b00001111,
	HEAD_FOUR    = 0b00000111,
};

inline bool match(const std::uint8_t unit, const CodeUnitType type) {
	return unit & static_cast<std::uint8_t>(type);
}

inline void write(char32_t& point,
                  const std::uint8_t unit,
                  const CodePoint mask,
                  const std::uint8_t offset) {
	point += (unit & static_cast<std::uint8_t>(mask)) << offset;
}

}
}

#endif  // CODEPOINT_ITERATOR_UTILITY_H_
