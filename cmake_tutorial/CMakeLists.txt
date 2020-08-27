cmake_minimum_required(VERSION 3.10)

project(hottspot_capital VERSION 0.0.1)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

option(USE_MYMATH "Use tutorial provided math implementation" ON)

configure_file(tutorial_config.h.in tutorial_config.h)

if(USE_MYMATH)
  add_subdirectory(MathFunctions)
  list(APPEND EXTRA_LIBS MathFunctions)
  list(APPEND EXTRA_INCLUDES MathFunctions)
endif()

add_executable(hottspot_capital tutorial.cpp)
add_library(MathFunctions mysqrt.cpp)

target_link_libraries(hottspot_capital PUBLIC ${EXTRA_LIBS})
target_include_directories(hottspot_capital PUBLIC "${PROJECT_BINARY_DIR}"
                                                   ${EXTRA_INCLUDES})
