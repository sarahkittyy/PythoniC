cmake_minimum_required(VERSION 3.13)
project(RangesExample)

file(GLOB sources "*.cpp")
add_executable(Ranges ${sources})

target_link_libraries(
	Ranges
	PythoniC
)

target_include_directories(
	Ranges
	PUBLIC
	"../../include/"
)