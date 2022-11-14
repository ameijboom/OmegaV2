cmake_minimum_required(VERSION 3.21)
project(omega LANGUAGES CXX)

set (CMAKE_CXX_STANDARD 23)
set (CMAKE_BUILD_TYPE RelWithDebInfo)

include(FetchContent)
FetchContent_Declare(SFML
        GIT_REPOSITORY https://github.com/SFML/SFML.git
        GIT_TAG 2.6.x)
FetchContent_MakeAvailable(SFML)

add_executable(Omega2 src/main.cpp src/Core/Game.cpp src/UI/Button.cpp)

file(COPY assets DESTINATION ${CMAKE_BINARY_DIR})

target_include_directories(Omega2 PRIVATE "include")
target_include_directories(Omega2 PRIVATE "include/Core")
target_include_directories(Omega2 PRIVATE "assets")
target_link_libraries(Omega2 PRIVATE sfml-graphics sfml-window sfml-audio)

if (WIN32 AND BUILD_SHARED_LIBS)
    add_custom_command(TARGET omega POST_BUILD
            COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_RUNTIME_DLLS:omega> $<TARGET_FILE_DIR:omega> COMMAND_EXPAND_LISTS)
endif()

install(TARGETS Omega2)
