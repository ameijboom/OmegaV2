cmake_minimum_required(VERSION 3.21)
project(omega LANGUAGES CXX)

set (CMAKE_CXX_STANDARD 23)
set (CMAKE_BUILD_TYPE RelWithDebInfo)

include(FetchContent)
FetchContent_Declare(SFML
        GIT_REPOSITORY https://github.com/SFML/SFML.git
        GIT_TAG 2.6.x)
FetchContent_MakeAvailable(SFML)

FetchContent_Declare(json URL https://github.com/nlohmann/json/releases/download/v3.11.2/json.tar.xz)
FetchContent_MakeAvailable(json)

add_executable(omega src/main.cpp src/Core/Game.cpp src/UI/Button.cpp src/Core/Event.cpp src/Core/Scene.cpp src/Core/Battle.cpp src/Entities/Entity.cpp src/UI/Textbox.cpp src/UI/Display.cpp src/UI/DisplayText.cpp)

file(COPY assets DESTINATION ${CMAKE_BINARY_DIR})

target_include_directories(omega PRIVATE "include")
target_include_directories(omega PRIVATE "include/Core")
target_include_directories(omega PRIVATE "assets")
target_link_libraries(omega PRIVATE sfml-graphics sfml-window sfml-audio nlohmann_json::nlohmann_json)

if (WIN32 AND BUILD_SHARED_LIBS)
    add_custom_command(TARGET omega POST_BUILD
            COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_RUNTIME_DLLS:omega> $<TARGET_FILE_DIR:omega> COMMAND_EXPAND_LISTS)
endif()

install(TARGETS omega)
