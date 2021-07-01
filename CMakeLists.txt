cmake_minimum_required(VERSION 3.19)

project(Nock VERSION 0.0.1)

set(MAIN_EXEC_NAME nock)

include("FindOpenGL")

set(SOURCES
	lib/glew/src/glew.c
	lib/glad/glad.c
	src/array.cpp
	src/game.cpp
	src/graphics.cpp
	src/main.cpp
	src/log.cpp
	)

add_executable(${MAIN_EXEC_NAME} ${SOURCES})

target_include_directories(${MAIN_EXEC_NAME} PRIVATE "src")
target_include_directories(${MAIN_EXEC_NAME} PRIVATE "lib")

target_link_libraries(${MAIN_EXEC_NAME} m)
target_link_libraries(${MAIN_EXEC_NAME} GL)
target_link_libraries(${MAIN_EXEC_NAME} glfw)
target_link_libraries(${MAIN_EXEC_NAME} dl)
