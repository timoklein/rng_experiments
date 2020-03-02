cmake_minimum_required(VERSION 3.5)

project(RNG LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Source files
set( project_sources
   main.cpp
   sfc.h
   jsf.h
)

# Create executable with all necessary source files
add_executable(${PROJECT_NAME}
  ${project_sources}
)
