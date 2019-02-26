cmake_minimum_required(VERSION 3.13)
project(Examples)

file(GLOB_RECURSE sources "*.cpp")
foreach(source ${sources})
	string(REGEX REPLACE ".*/(.*)\.cpp" "\\1" executable ${source})
	add_executable(${executable} ${source})
	target_link_libraries(
		${executable}
		PythoniC
	)
endforeach()