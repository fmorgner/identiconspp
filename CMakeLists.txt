cmake_minimum_required(VERSION 3.2)
project("png" CXX)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake/modules/")

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")
set(CXX_VERSION "c++14")

include("CompilerSetup")
include("ConanPackages")

include_directories("include")
add_subdirectory("src")
