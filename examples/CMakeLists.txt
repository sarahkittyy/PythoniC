cmake_minimum_required(VERSION 3.13)
project(Examples)

file(GLOB_RECURSE sources "${PROJECT_SOURCE_DIR}/examples/*.cpp")
foreach(source ${sources})
	string(REGEX REPLACE ".*/(.*)\.cpp" "\\1" executable ${source})
	add_executable(${executable} ${source})
	find_library(PYTHONIC pythonic "${PROJECT_SOURCE_DIR}/build/")
	target_link_libraries(
		${executable}
		${PYTHONIC}
	)
endforeach()