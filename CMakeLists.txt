cmake_minimum_required(VERSION 2.8.12)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS OFF)

option(SFD_BUILD_EXAMPLE "Build example" ON)

project(Sfd C)
add_library(
	Sfd STATIC
	${CMAKE_CURRENT_SOURCE_DIR}/src/sfd.c
)
target_include_directories(Sfd
	PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src/
)
if(WIN32 OR CYGWIN)
	target_compile_definitions(Sfd PUBLIC SFD_BACKEND_WIN32)
	target_link_libraries(Sfd PUBLIC comdlg32)
else()
	target_compile_definitions(Sfd PUBLIC SFD_BACKEND_ZENITY)
endif()

if(SFD_BUILD_EXAMPLE)
	project(Sfd_Example C)
	add_executable(Sfd_Example ${CMAKE_CURRENT_SOURCE_DIR}/src/example.c)
	target_link_libraries(Sfd_Example PUBLIC Sfd)
endif()
