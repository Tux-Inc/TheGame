cmake_minimum_required(VERSION 3.10)  # CMake version check

project(game)   



set(CMAKE_CXX_STANDARD 14)
# set(CMAKE_CXX_FLAGS "-g3")

# message(STATUS "CXX from ENV: $ENV{CXX}")

set (CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR})



find_package(SFML 2.5 COMPONENTS graphics audio REQUIRED)

set(SRC 
    src/main.cpp
    src/utils/transform.cpp
    src/entities/Entity.cpp
    src/entities/Player.cpp
    src/entities/Enemy.cpp
    src/entities/EntityManager.cpp
    src/renderer/Sfml.cpp
)

add_executable(${PROJECT_NAME} ${SRC})

target_link_libraries(${PROJECT_NAME} sfml-graphics sfml-audio)

target_include_directories(${PROJECT_NAME} PRIVATE src/entities/ src/utils/ src/interfaces src/renderer/)
 