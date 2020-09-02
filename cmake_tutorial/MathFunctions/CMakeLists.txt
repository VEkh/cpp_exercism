add_library(MathFunctions MathFunctions.cpp
                          "${CMAKE_CURRENT_BINARY_DIR}/table.h")

target_include_directories(MathFunctions INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})

option(USE_MYMATH "Use tutorial provided math implementation" ON)

if(USE_MYMATH)
  target_compile_definitions(MathFunctions PRIVATE "USE_MYMATH")
  add_executable(make_table make_table.cpp)

  add_custom_command(
    OUTPUT ${CMAKE_CURRENT_BINARY_DIR}/table.h
    COMMAND make_table ${CMAKE_CURRENT_BINARY_DIR}/table.h
    DEPENDS make_table)

  add_library(SqrtLibrary mysqrt.cpp ${CMAKE_CURRENT_BINARY_DIR}/table.h)
  target_include_directories(SqrtLibrary PRIVATE ${CMAKE_CURRENT_BINARY_DIR})
  set_target_properties(SqrtLibrary PROPERTIES POSITION_INDEPENDENT_CODE
                                               ${BUILD_SHARED_LIBS})
  target_link_libraries(MathFunctions PRIVATE SqrtLibrary)
endif()

target_compile_definitions(MathFunctions PRIVATE "EXPORTING_MYMATH")

install(TARGETS MathFunctions DESTINATION lib)
install(FILES MathFunctions.h DESTINATION include)
