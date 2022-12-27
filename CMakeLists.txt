# CMakeList.txt : CMake project for OptimizedClickHandler, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

project ("OptimizedClickHandler")

# Add source to this project's executable.
add_executable (OptimizedClickHandler "OptimizedClickHandler.cpp" "OptimizedClickHandler.h" "OptimizedClickHandlerUtils.h" "OptimizedClickHandlerUtils.cpp")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET OptimizedClickHandler PROPERTY CXX_STANDARD 20)
endif()

# TODO: Add tests and install targets if needed.
