cmake_minimum_required(VERSION 3.28.3)
project(Lab3 C)

find_package(FLEX REQUIRED)
FLEX_TARGET(Lexer lexer.l ${CMAKE_CURRENT_BINARY_DIR}/lex.yy.c)

add_executable(Lab3 symtab.c ${FLEX_Lexer_OUTPUTS})
target_include_directories(Lab3 PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})