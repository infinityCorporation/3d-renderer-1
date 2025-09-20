cmake_minimum_required(VERSION 3.10)
project(Render)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add your main.cc file to the executable
add_executable(render main.cc)
