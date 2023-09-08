cmake_minimum_required(VERSION 3.27)
project(dungeon-explorer VERSION 0.1.0 LANGUAGES C CXX)

# Add all .cpp files
file(GLOB_RECURSE SOURCES "src/*.cpp")

# Add your executable target
add_executable(dungeon-explorer ${SOURCES})

# Check the platform and set the lib folder accordingly
if(APPLE)
    # If it's a Mac, set the lib folder to a different path
    set(wxWidgets_ROOT_DIR "${CMAKE_SOURCE_DIR}/libs/wxWidgets_mac")
else()
    # For other platforms, use the default lib folder path
    set(wxWidgets_ROOT_DIR "${CMAKE_SOURCE_DIR}/libs/wxWidgets")
endif()

find_package(wxWidgets REQUIRED core base)

# Add the include directories for wxWidgets
include(${wxWidgets_USE_FILE})

# Link with wxWidgets libraries
target_link_libraries(dungeon-explorer PRIVATE ${wxWidgets_LIBRARIES})
