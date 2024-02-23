cmake_minimum_required(VERSION 3.5.0 FATAL_ERROR)

set(ROOT_PATH ../..)

project(Project)

set(CMAKE_INCLUDE_CURRENT_DIR ON)


if (POLICY CMP0074)
cmake_policy(SET CMP0074 NEW)
endif()

set(HEADERS
    	./include/general_objects.h
    	./include/idw_interpolator.h
    	./include/utilities.h
)

set(SOURCES
    	./src/Source.cpp
    	./src/general_objects.cpp
    	./src/idw_interpolator.cpp
	./src/utilities.cpp
)

source_group ("Header Files" FILES ${HEADERS})
source_group ("Source Files" FILES ${SOURCES})

add_executable(${PROJECT_NAME} ${HEADERS} ${SOURCES})

add_subdirectory(lib/nlohmann)
target_link_libraries (${PROJECT_NAME}
  	PUBLIC
	nlohmann_json
)

target_include_directories(${PROJECT_NAME} 
PUBLIC 
./include
)



