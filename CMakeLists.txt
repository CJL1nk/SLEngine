cmake_minimum_required(VERSION 3.30)
project(SLEngine)

set(CMAKE_CXX_STANDARD 20)

include(FetchContent)
FetchContent_Declare(SFML
        GIT_REPOSITORY https://github.com/SFML/SFML.git
        GIT_TAG 3.0.1
        GIT_SHALLOW ON
        EXCLUDE_FROM_ALL
        SYSTEM)
FetchContent_MakeAvailable(SFML)

add_executable(SLEngine src/main.cpp
)

target_link_libraries(SLEngine PRIVATE SFML::Graphics SFML::Window SFML::Audio)