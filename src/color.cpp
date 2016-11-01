#include "byte_iterator.hpp"
#include "color.hpp"

color color::make(std::string const & bytes)
  {
  auto it = byte_iterator{bytes};
  return color{*(it++), *(it++), *it};
  }
