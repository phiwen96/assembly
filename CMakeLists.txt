cmake_minimum_required (VERSION 3.19.4)
get_filename_component (self ${CMAKE_CURRENT_SOURCE_DIR} NAME)

project (
	${self}
	VERSION 1.0
	DESCRIPTION "Very nice project"
	LANGUAGES CXX ASM
)	

add_subdirectory (cmake/phake)


# enable_language(ASM)
 
if (CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME)
	# Let's ensure -std=g++xx instead of -std=c++xx
	set (CMAKE_CXX_STANDARD 20)
	set (CMAKE_CXX_STANDARD_REQUIRED ON)
	set (CMAKE_CXX_EXTENSIONS ON)

	# Let's nicely support folders in IDEs
	set_property (GLOBAL PROPERTY USE_FOLDERS ON)
	include (CTest)

endif()

add_subdirectory (src)

include (CTest)

add_subdirectory (tests)