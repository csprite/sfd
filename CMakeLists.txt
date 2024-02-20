cmake_minimum_required(VERSION 2.8.12)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS OFF)

project(Sfd C)
add_library(
	Sfd STATIC
	${CMAKE_CURRENT_SOURCE_DIR}/src/sfd.c
)
target_include_directories(Sfd
	PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src/
)
if(WIN32 OR CYGWIN)
	target_compile_definitions(Sfd PUBLIC SFD_TARGET_WINDOWS)
	target_link_libraries(Sfd PUBLIC comdlg32)
endif()
