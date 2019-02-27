cmake_minimum_required(VERSION 3.13)
project(PythoniC)

# Programmer's use only, this should never be set.
option(__BUILD_TESTING__ 
"DO NOT TOGGLE" OFF)

option(BUILD_EXAMPLES 
"Builds the example programs inside examples/" ON)

file(GLOB_RECURSE sources src/*.cpp)
if(sources NOT STREQUAL "")
	add_library(PythoniC STATIC ${sources})
endif()

set(CMAKE_CXX_FLAGS "-g -Wall -Wno-unused-variable")
set(CMAKE_CXX_STANDARD 17)

include_directories(
	"${CMAKE_SOURCE_DIR}/include/"
)

if(__BUILD_TESTING__)
	add_subdirectory("testing")
endif()

if(BUILD_EXAMPLES)
	add_subdirectory("examples")
endif()

set_target_properties(PythoniC PROPERTIES OUTPUT_NAME "pythonic")