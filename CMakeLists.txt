cmake_minimum_required(VERSION 3.5)
project(lol)

set(testm test_matrix)
add_executable(${testm} samples/sample_matrix.cpp)

set(Matrix tmatrix)

add_library(${Matrix})
target_link_libraries(${testm} PUBLIC ${Matrix})
target_include_directories(tmatrix PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include")
target_sources(${Matrix} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include/tmatrix.h)
set_target_properties(tmatrix PROPERTIES LINKER_LANGUAGE CXX)
