cmake_minimum_required(VERSION 3.10)

project(tutorial VERSION 0.0.1)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}")

option(BUILD_SHARED_LIBS "Build using shared libraries" ON)

configure_file(tutorial_config.h.in tutorial_config.h)
add_subdirectory(MathFunctions)

add_executable(tutorial tutorial.cpp)

target_link_libraries(tutorial PUBLIC MathFunctions)
target_include_directories(tutorial PUBLIC "${PROJECT_BINARY_DIR}")

install(TARGETS tutorial DESTINATION bin)
install(FILES "${PROJECT_BINARY_DIR}/tutorial_config.h" DESTINATION include)

include(CTest)

# does the application run
add_test(NAME Runs COMMAND tutorial 25)

# does the usage message work?
add_test(NAME Usage COMMAND tutorial)
set_tests_properties(Usage PROPERTIES PASS_REGULAR_EXPRESSION "Usage:.*number")

# define a function to simplify adding tests
function(do_test target arg result)
  add_test(NAME Comp${arg} COMMAND ${target} ${arg})
  set_tests_properties(Comp${arg} PROPERTIES PASS_REGULAR_EXPRESSION ${result})
endfunction(do_test)

# do a bunch of result based tests
do_test(tutorial 4 "4 is 2")
do_test(tutorial 9 "9 is 3")
do_test(tutorial 5 "5 is 2.236")
do_test(tutorial 7 "7 is 2.645")
do_test(tutorial 25 "25 is 5")
do_test(tutorial -25 "-25 is [-nan|nan|0]")
do_test(tutorial 0.0001 "0.0001 is 0.01")

include(InstallRequiredSystemLibraries)
set(CPACK_PACKAGE_VERSION_MAJOR "${tutorial_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${tutorial_VERSION_MINOR}")
set(CPACK_RESOURCE_FILE_LICENSE "${CMAKE_CURRENT_SOURCE_DIR}/License.txt")
include(CPack)
