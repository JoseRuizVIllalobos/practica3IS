add_library(actividad actividad.cc actividad.h)
target_include_directories(actividad PUBLIC ${CMAKE_CURRENT_LIST_DIR})
add_executable(actividad-main actividad-main.cc)
target_link_libraries(actividad-main PUBLIC actividad)
