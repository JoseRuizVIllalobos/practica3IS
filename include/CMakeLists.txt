add_library(mainlib SHARED
	appexceptions.hpp
)
target_include_directories(mainlib PUBLIC
	${CMAKE_SOURCE_DIR}/include
)
set_target_properties(mainlib PROPERTIES LINKER_LANGUAGE CXX)

add_library(mysql SHARED IMPORTED)


