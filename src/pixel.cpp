#include "color.hpp"
#include "pixel.hpp"

#include <pngwriter.h>

void pixel::draw(pngwriter & image, color const & color, unsigned size, unsigned margin)
  {
  auto const x = this->x * size + margin;
  auto const y = this->y * size + margin;

  image.filledsquare(
    x,
    y,
    x + size,
    y + size,
    color.red * 196,
    color.green * 196,
    color.blue * 196
    );
  }

