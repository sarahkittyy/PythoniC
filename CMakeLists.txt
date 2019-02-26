cmake_minimum_required(VERSION 3.13)
project(PythoniC)

file(GLOB_RECURSE sources src/*.cpp)
add_library(PythoniC STATIC ${sources})

set(CMAKE_CXX_FLAGS "-g -Wall -Wno-unused-variable")
set(CMAKE_CXX_STANDARD 17)

include_directories(
	"${CMAKE_SOURCE_DIR}/include/"
)

# Get all subdirectories.
add_subdirectory("testing")
add_subdirectory("examples")

set_target_properties(PythoniC PROPERTIES OUTPUT_NAME "pythonic")