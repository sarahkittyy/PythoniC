cmake_minimum_required(VERSION 3.13)
project(PythoniC)

file(GLOB_RECURSE sources src/*.cpp)
add_library(PythoniC STATIC ${sources})

set(CMAKE_CXX_FLAGS "-Wall -Wno-unused-variable")
set(CMAKE_CXX_STANDARD 17)

target_include_directories(
	PythoniC
	PUBLIC
	"include"
)

# Get all subdirectories.
macro(subdirlist result curdir)
	file(GLOB children RELATIVE ${curdir} ${curdir}/*)
	set(dirlist "")
	foreach(child ${children})
		if(IS_DIRECTORY ${curdir}/${child})
			list(APPEND dirlist ${child})
		endif()
	endforeach()
	set(${result} ${dirlist})
endmacro()

add_subdirectory(
	"testing"
)

set(EXAMPLE_DIR "${PROJECT_SOURCE_DIR}/examples")

subdirlist(EXAMPLE_DIRS ${EXAMPLE_DIR})
foreach(dir ${EXAMPLE_DIRS})
	add_subdirectory("${EXAMPLE_DIR}/${dir}")
endforeach()

set_target_properties(PythoniC PROPERTIES OUTPUT_NAME "pythonic")