cmake_minimum_required(VERSION 3.28)
project(CHIPPIE
  LANGUAGES CXX
  VERSION 1.0
)


set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
# option(BUILD_SHARED_LIBS "Build shared libraries" OFF)


add_subdirectory(dependencies)
add_subdirectory(src)