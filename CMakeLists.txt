cmake_minimum_required(VERSION 3.10)  # CMake version check

project(game)

include(FetchContent)

set(FETCHCONTENT_QUIET FALSE)

set(CMAKE_CXX_STANDARD 14)

set (CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR})

set(SFML_VERSION 2.5.1)

FetchContent_Declare(
    SFML
    GIT_REPOSITORY "https://github.com/SFML/SFML.git"
    GIT_TAG        "${SFML_VERSION}"
)

FetchContent_GetProperties(sfml)
if(NOT sfml_POPULATED)
    FetchContent_Populate(sfml)
    add_subdirectory(${sfml_SOURCE_DIR} ${sfml_BINARY_DIR})
endif()


set(SRC
    src/main.cpp
    src/utils/transform.cpp
    src/entities/Entity.cpp
    src/entities/Player.cpp
    src/entities/Enemy.cpp
    src/entities/EntityManager.cpp
    src/renderer/Renderer.cpp
    src/renderer/Sfml.cpp
)

add_executable(${PROJECT_NAME} ${SRC})

target_link_libraries(${PROJECT_NAME} sfml-graphics sfml-audio)

target_include_directories(${PROJECT_NAME} PRIVATE src/entities/ src/utils/ src/interfaces src/renderer/ src/common/)

# Set Debug flags for your project
target_compile_options(${PROJECT_NAME} PRIVATE $<$<CONFIG:Debug>:-g3>)

# Set Release flags specifically for SFML library
set_target_properties(sfml-graphics PROPERTIES
    CMAKE_BUILD_TYPE Release
)
set_target_properties(sfml-audio PROPERTIES
    CMAKE_BUILD_TYPE Release
)
