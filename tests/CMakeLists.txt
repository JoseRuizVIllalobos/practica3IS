cmake_minimum_required(VERSION 3.16)

project(Tests)

# GTest include code for fetch content over the internet 
include(FetchContent)

FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG v1.14.0
)
FetchContent_MakeAvailable(googletest)
add_library(GTest::GTest INTERFACE IMPORTED)
target_link_libraries(GTest::GTest INTERFACE gtest_main gmock_main)
# End GTest include code

# Testing estadisticas library
add_executable(estadisticas-test estadisticas-test.cc)
target_link_libraries(estadisticas-test PRIVATE GTest::GTest)
target_include_directories(estadisticas-test PRIVATE ${CMAKE_SOURCE_DIR}/../include)
add_test(estadisticas_gtests estadisticas-test)

# Testing actividad library
add_executable(actividad-test actividad-test.cc)
target_link_libraries(actividad-test PRIVATE GTest::GTest)
target_include_directories(actividad-test PRIVATE ${CMAKE_SOURCE_DIR}/../include)
add_test(actividad_gtests actividad-test)



