#include "byte_iterator.hpp"
#include "color.hpp"
#include "pixel.hpp"

#include <pngwriter.h>

#include <iostream>
#include <limits>
#include <string>
#include <array>

auto constexpr kPixelsPerDimension = 8;
auto constexpr kMargin = 10;
auto constexpr kImageSize = 400 + 2 * kMargin;
auto constexpr kPixelSize = (kImageSize - 2 * kMargin) / kPixelsPerDimension;
auto constexpr kBackground = std::numeric_limits<std::uint16_t>::max() * 90 / 100;

int main(int argc, char * * argv) try
  {
  if(argc != 2)
    {
    std::cerr << "png <sha256sum>\n";
    return 1;
    }

  auto hex = std::string{argv[1]};
  if(hex.size() != 64)
    {
    std::cerr << "png <sha256sum>\n";
    return 1;
    }

  auto it = hex.cbegin();
  auto flags = std::array<std::array<bool, kPixelsPerDimension>, kPixelsPerDimension>{};
  for(auto i = 0u; i < kPixelsPerDimension; ++i)
    {
    for(auto j = 0u; j < kPixelsPerDimension; j++)
      {
      flags[i][j] ^= !(*(it++) % 2);
      }
    }

  auto png = pngwriter{420, 420, kBackground, "identicon.png"};
  auto const col = color::make(hex);
  for(auto i = 0u; i < kPixelsPerDimension / 2; ++i)
    {
    for(auto j = 0u; j < kPixelsPerDimension; ++j)
      {
      if(flags[i][j] ^ flags[kPixelsPerDimension - i][j])
        {
        pixel{i, j}.draw(png, col, kPixelSize, kMargin);
        pixel{kPixelsPerDimension - 1 - i, j}.draw(png, col, kPixelSize, kMargin);
        }
      }
    }

  png.close();
  }
catch(std::exception & e)
  {
  std::cerr << e.what() << '\n';
  }
