cmake_minimum_required(VERSION 3.10)

set(CMAKE_CXX_STANDARD 17)
project(compiler CXX)

# 设置可执行文件输出目录为 bin
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# 设置库文件输出目录为 lib
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)

add_executable(${PROJECT_NAME}
        src/error.h
        src/ast_visitor.h)

target_include_directories(
        ${PROJECT_NAME}
        PUBLIC ${PROJECT_SOURCE_DIR}/antlr/src
        PUBLIC ${PROJECT_SOURCE_DIR}/antlr/src/atn
        PUBLIC ${PROJECT_SOURCE_DIR}/antlr/src/dfa
        PUBLIC ${PROJECT_SOURCE_DIR}/antlr/src/misc
        PUBLIC ${PROJECT_SOURCE_DIR}/antlr/src/support
        PUBLIC ${PROJECT_SOURCE_DIR}/antlr/src/tree
        PUBLIC ${PROJECT_SOURCE_DIR}/antlr/src/tree/pattern
        PUBLIC ${PROJECT_SOURCE_DIR}/antlr/src/tree/xpath
        PUBLIC ${PROJECT_SOURCE_DIR}/grammar
)

target_compile_options(${PROJECT_NAME} PRIVATE "/MD$<$<CONFIG:Debug>:d>")

add_subdirectory(src)
add_subdirectory(grammar)
add_subdirectory(antlr)



