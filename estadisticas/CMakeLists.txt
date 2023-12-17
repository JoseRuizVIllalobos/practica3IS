add_library(estadisticas estadisticas.cc estadisticas.h)
target_link_libraries(estadisticas PUBLIC acividad)
 target_include_directories(estadisticas PUBLIC ${CMAKE_CURRENT_LIST_DIR})

 add_executable(estadisticas-main estadisticas-main.cc)
 target_link_libraries(estadisticas-main PUBLIC estadisticas)