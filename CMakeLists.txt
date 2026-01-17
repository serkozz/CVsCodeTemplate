cmake_minimum_required(VERSION 3.20)

project(App LANGUAGES C)

# Force Debug mode for GDB symbols
if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Debug)
endif()

# Set output directory to 'bin' inside the build folder
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")

# Faster debug
add_compile_options(-gdwarf-5 -gpubnames)

# Find all source files in the src directory
file(GLOB_RECURSE SOURCES "src/*.c")

# Create the executable
add_executable(App ${SOURCES})

# Ensure the compiler finds headers if you have an 'include' folder later
target_include_directories(App PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/src")