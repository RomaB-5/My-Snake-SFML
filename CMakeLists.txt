cmake_minimum_required(VERSION 3.16)
project(CMakeSFMLProject LANGUAGES CXX)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
option(BUILD_SHARED_LIBS "Build shared libraries" OFF)

include(FetchContent)
FetchContent_Declare(SFML
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG 2.6.x)
FetchContent_MakeAvailable(SFML)


add_custom_target(copy_resources ALL
        COMMAND ${CMAKE_COMMAND} -E copy_directory
        ${PROJECT_SOURCE_DIR}/assets
        ${PROJECT_BINARY_DIR}/bin/assets
        COMMENT "Copying resources into binary directory")

# add_dependencies(RoE copy_resources)

add_executable(CMakeSFMLProject src/main.cpp "include/MyLibrary/Snake.h"  "src/MyLibrary/Snake.cpp" "include/MyLibrary/Game.h" "src/MyLibrary/Game.cpp"  "include/MyLibrary/TextureManager.h" "src/MyLibrary/TextureManager.cpp" "include/MyLibrary/EmptyTileGenerator.h" "src/MyLibrary/EmptyTileGenerator.cpp" "include/MyLibrary/Fruit.h" "src/MyLibrary/Fruit.cpp" "include/util/SpriteNormalizer.h" "src/util/NormalizeSprite.cpp" "include/MyLibrary/SpriteManager.h" "src/MyLibrary/SpriteManager.cpp")


target_link_libraries(CMakeSFMLProject PRIVATE sfml-graphics)
target_compile_features(CMakeSFMLProject PRIVATE cxx_std_17)


if(WIN32)
    add_custom_command(
        TARGET CMakeSFMLProject
        COMMENT "Copy OpenAL DLL"
        PRE_BUILD COMMAND ${CMAKE_COMMAND} -E copy ${SFML_SOURCE_DIR}/extlibs/bin/$<IF:$<EQUAL:${CMAKE_SIZEOF_VOID_P},8>,x64,x86>/openal32.dll $<TARGET_FILE_DIR:CMakeSFMLProject>
        VERBATIM)
endif()

install(TARGETS CMakeSFMLProject)
