project(ClangTool)
cmake_minimum_required(VERSION 3.0)

aux_source_directory(./src SRC_LIST)

execute_process(COMMAND llvm-config --libs --system-libs OUTPUT_VARIABLE LLVM_LIBS)
string(REGEX REPLACE "[\n\ ]" ";" LLVM_LIBS ${LLVM_LIBS})

add_executable(${PROJECT_NAME} ${SRC_LIST})

target_link_libraries(${PROJECT_NAME}
  clangTooling
  clangASTMatchers
  clangFrontend
  clangSerialization
  clangDriver
  clangParse
  clangSema
  clangAnalysis
  clangAST
  clangBasic
  clangEdit
  clangLex
  ${LLVM_LIBS}
)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fno-rtti -fno-exceptions -std=c++1y")
