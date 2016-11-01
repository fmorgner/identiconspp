#ifndef FMO_IDENTICONSPP_PIXEL_H
#define FMO_IDENTICONSPP_PIXEL_H

#include <pngwriter.h>

struct pixel
  {
  unsigned const x;
  unsigned const y;

  void draw(pngwriter & image, struct color const & color, unsigned size, unsigned margin);
  };

#endif
