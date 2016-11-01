add_executable(
  png
  main.cpp
  pixel.cpp
  color.cpp
  )

target_link_libraries(png ${CONAN_LIBS} harfbuzz)
