cmake_minimum_required(VERSION 3.16)

project(ProyectoGestionEventos)

add_subdirectory(include)

add_executable(gestor src/main.cpp)

# Librerías MySQL
add_library(mysql SHARED IMPORTED)
set_target_properties( mysql PROPERTIES IMPORTED_LOCATION 
	${CMAKE_SOURCE_DIR}/lib64/libmysqlcppconn.so
)

target_link_libraries(gestor
	mainlib
	mysql
)
	
set_target_properties(gestor PROPERTIES LINKER_LANGUAGE CXX)
