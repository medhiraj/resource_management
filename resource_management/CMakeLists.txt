# CMakeList.txt : CMake project for ResourceManagement, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

project ("ResourceManagement" VERSION 1.0)
#add_subdirectory("src")
# specify the C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)
# Add source to this project's executable.

file(GLOB ResourceManagement_SRC CONFIGURE_DEPENDS "include/*.h" "src/*.cpp")
include_directories("${CMAKE_SOURCE_DIR}/include")

add_subdirectory(src)
add_subdirectory(gtest)
add_subdirectory(lib/googletest)

#target_include_directories(ResourceManagement PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include")
#add_executable (ResourceManagement ${ResourceManagement_SRC})

# TODO: Add tests and install targets if needed.
