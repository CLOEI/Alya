#pragma once
#include <cstdint>

namespace endian {

inline uint16_t swap16(uint16_t value) { return (value >> 8) | (value << 8); }

inline uint32_t swap32(uint32_t value) {
  return ((value >> 24) & 0x000000FF) | ((value >> 8) & 0x0000FF00) |
         ((value << 8) & 0x00FF0000) | ((value << 24) & 0xFF000000);
}

inline uint64_t swap64(uint64_t value) {
  return ((value >> 56) & 0x00000000000000FFULL) |
         ((value >> 40) & 0x000000000000FF00ULL) |
         ((value >> 24) & 0x0000000000FF0000ULL) |
         ((value >> 8) & 0x00000000FF000000ULL) |
         ((value << 8) & 0x000000FF00000000ULL) |
         ((value << 24) & 0x0000FF0000000000ULL) |
         ((value << 40) & 0x00FF000000000000ULL) |
         ((value << 56) & 0xFF00000000000000ULL);
}

inline uint16_t to_little_endian16(uint16_t value) {
#if __BYTE_ORDER__ == __ORDER_BIG_ENDIAN__
  return swap16(value);
#else
  return value;
#endif
}

inline uint32_t to_little_endian32(uint32_t value) {
#if __BYTE_ORDER__ == __ORDER_BIG_ENDIAN__
  return swap32(value);
#else
  return value;
#endif
}

inline uint64_t to_little_endian64(uint64_t value) {
#if __BYTE_ORDER__ == __ORDER_BIG_ENDIAN__
  return swap64(value);
#else
  return value;
#endif
}

} 
