cmake_minimum_required(VERSION 3.27)
project(dungeon-explorer VERSION 0.1.0 LANGUAGES C CXX)

#add all .cpps 
file(GLOB_RECURSE SOURCES "src/*.cpp")

# Add your executable target
add_executable(dungeon-explorer ${SOURCES})

# Specify the root directory of wxWidgets
set(wxWidgets_ROOT_DIR "${CMAKE_SOURCE_DIR}/libs/wxWidgets")
find_package(wxWidgets REQUIRED core base)

# Add the include directories for wxWidgets
include(${wxWidgets_USE_FILE})

# Link with wxWidgets libraries
target_link_libraries(dungeon-explorer PRIVATE ${wxWidgets_LIBRARIES})
