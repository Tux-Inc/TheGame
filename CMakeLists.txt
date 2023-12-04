cmake_minimum_required(VERSION 3.10)

project(game)

include(FetchContent)

set(FETCHCONTENT_QUIET FALSE)

set(CMAKE_CXX_STANDARD 14)

set (CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR})

set(SFML_VERSION 2.5.1)

# set(FREETYPE_VERSION 2.6.5)

# FetchContent_Declare(
#     FreeType
#     GIT_REPOSITORY "https://github.com/freetype/freetype.git"
#     GIT_TAG        "${FREETYPE_VERSION}"
# )

# FetchContent_GetProperties(freetype)
# if(NOT freetype_POPULATED)
#     FetchContent_Populate(freetype)
#     add_subdirectory(${freetype_SOURCE_DIR} ${freetype_BINARY_DIR})
# endif()

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


# set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
# option(BUILD_SHARED_LIBS "Build shared libraries" OFF)

# include(./CPM/cmake/CPM.cmake)

# # CPMAddPackage(
# #     NAME FreeType
# #     GIT_TAG 2.6.5
# #     GIT_REPOSITORY https://github.com/freetype/freetype.git
# # )

# # add_library(freetype STATIC IMPORTED)
# # set_target_properties(freetype PROPERTIES
# #     IMPORTED_LOCATION ${freetype_SOURCE_DIR}/objs/.libs/libfreetype.a
# #     INTERFACE_INCLUDE_DIRECTORIES ${freetype_SOURCE_DIR}/include
# # )
# # target_link_libraries(freetype INTERFACE ${CMAKE_DL_LIBS})
# # target_compile_definitions(freetype INTERFACE FT2_BUILD_LIBRARY)

# CPMAddPackage(
#     NAME SFML
#     GIT_TAG 2.5.1
#     GIT_REPOSITORY https://github.com/SFML/SFML.git
# )

# add_executable(CMakeSFMLProject src/main.cpp)
# target_link_libraries(CMakeSFMLProject PRIVATE sfml-graphics)
# target_compile_features(CMakeSFMLProject PRIVATE cxx_std_17)

# if(WIN32)
#     add_custom_command(
#         TARGET CMakeSFMLProject
#         COMMENT "Copy OpenAL DLL"
#         PRE_BUILD COMMAND ${CMAKE_COMMAND} -E copy ${SFML_SOURCE_DIR}/extlibs/bin/$<IF:$<EQUAL:${CMAKE_SIZEOF_VOID_P},8>,x64,x86>/openal32.dll $<TARGET_FILE_DIR:CMakeSFMLProject>
#         VERBATIM)
# endif()

set(SRC
    src/main.cpp
    src/utils/transform.cpp
    src/entities/Entity.cpp
    src/entities/Player.cpp
    src/entities/Enemy.cpp
    src/entities/Cone.cpp
    src/renderer/Renderer.cpp
    src/renderer/Sfml.cpp
    src/manager/EntityManager.cpp
    src/manager/SceneManager.cpp
    src/manager/Core.cpp
    src/scenes/Scene.cpp
    src/scenes/Game.cpp
    src/scenes/Menu.cpp
    src/map/Map.cpp
    src/map/TileMap.cpp
   src/music/MyMusic.cpp
    src/manager/MusicManager.cpp
)

add_executable(${PROJECT_NAME} ${SRC})

target_link_libraries(${PROJECT_NAME} sfml-graphics sfml-audio)

target_include_directories(${PROJECT_NAME} PRIVATE
        src/entities/
        src/utils/
        src/interfaces/
        src/renderer/
        src/common/
        src/manager/
        src/scenes/
        src/map/
        src/music/
        src/sound/
)

# Set Debug flags for your project
target_compile_options(${PROJECT_NAME} PRIVATE $<$<CONFIG:Debug>:-g3>)

# Set Release flags specifically for SFML library
set_target_properties(sfml-graphics PROPERTIES
    CMAKE_BUILD_TYPE Release
)
set_target_properties(sfml-audio PROPERTIES
    CMAKE_BUILD_TYPE Release
)
