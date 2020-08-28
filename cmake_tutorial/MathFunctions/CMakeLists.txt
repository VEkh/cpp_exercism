add_executable(make_table make_table.cpp)

add_custom_command(
  OUTPUT ${CMAKE_CURRENT_BINARY_DIR}/table.h
  COMMAND make_table ${CMAKE_CURRENT_BINARY_DIR}/table.h
  DEPENDS make_table)

add_library(MathFunctions mysqrt.cpp "${CMAKE_CURRENT_BINARY_DIR}/table.h")

target_include_directories(
  MathFunctions
  INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}
  PRIVATE ${CMAKE_CURRENT_BINARY_DIR})

install(TARGETS MathFunctions DESTINATION lib)
install(FILES MathFunctions.h DESTINATION include)
