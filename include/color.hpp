#ifndef FMO_IDENTICONSPP_COLOR_H
#define FMO_IDENTICONSPP_COLOR_H

#include <cstdint>
#include <string>

struct color
  {
  std::uint8_t const red;
  std::uint8_t const green;
  std::uint8_t const blue;

  static color make(std::string const & bytes);
  };

#endif
