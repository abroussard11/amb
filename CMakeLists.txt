############################
# Top level amb CMake file #
############################

cmake_minimum_required( VERSION 2.8 )
project( amb )

include(CMakeVars.txt)

include_directories("src")

add_subdirectory( src )
