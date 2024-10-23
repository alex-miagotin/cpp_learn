# general info
cmake_minimum_required (VERSION 3.16.3)
message(STATUS "CMAKE version: ${CMAKE_VERSION}")

if (WIN32)
    message(STATUS "OS: Windows")
elseif(LINUX)
    message(STATUS "OS: Linux")
else()
    message(STATUS "OS: unknown")
endif()

if (PROJECT_NAME)
    message(STATUS "Project name: ${PROJECT_NAME}")
else()
    message(STATUS "Project name: not set. Set to default cmake_project")
    set(PROJECT_NAME "cmake_project")
endif()

# common options
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin/archive)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT ${PROJECT_NAME})
set_property(GLOBAL PROPERTY USE_FOLDERS OFF)
set(CMAKE_CXX_REGENERATION TRUE)

# cpp options
set(CMAKE_CXX_STANDARD 20)
message(STATUS "CXX Standart: ${CMAKE_CXX_STANDARD}")
# set(CMAKE_BUILD_TYPE Debug)
message(STATUS "Build type: ${CMAKE_BUILD_TYPE}")
set(CMAKE_TOOLCHAIN_FILE "conan_toolchain.cmake")
# set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -save-temps=obj -Wall -Wextra")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra")
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -g") # -g -s -Ofast
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -O3")
set(LINKER_FLAGS "${LINKER_FLAGS} -Wl,-i")


# Main project
set (SOURCES
    src/main.cpp
)

set (INCLUDES
)

project(${PROJECT_NAME} VERSION 0.0.1 DESCRIPTION "CMake project")
add_executable(
    ${PROJECT_NAME} 
    ${SOURCES}
    ${INCLUDES}
)

option(SKIP_GAME_OPTION "Skip game" OFF)
if(SKIP_GAME_OPTION)
    message(STATUS "Skip game")
    target_compile_definitions(${PROJECT_NAME} PRIVATE SKIP_GAME)
elseif()
    message(STATUS "Build game")
endif()

target_precompile_headers(${PROJECT_NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/src/pch.hpp)

# Math library - static
set(MATH_SOURCES
    src/utils/Math.cpp
)
set(MATH_INCLUDES
    src/utils/Math.hpp
)
add_library(utils_library STATIC ${MATH_SOURCES} ${MATH_INCLUDES})
target_include_directories(utils_library PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/src)

# Game library - dll
set(DLL_GAME_SOURCES
    src/game/Character.cpp
    src/game/Weapon.cpp
)
set(DLL_GAME_INCLUDES
    src/game/Character.hpp
    src/game/Weapon.hpp
)
add_library(game_library SHARED ${DLL_GAME_SOURCES} ${DLL_GAME_INCLUDES})
target_include_directories(game_library PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src)

if (WIN32)
    # TODO: check on windows with msbuild
    target_compile_definitions(game_library PUBLIC _EXPORTING)
    target_compile_definitions(${PROJECT_NAME} PUBLIC _IMPORTING)
endif()

message("Using ${CMAKE_CXX_COMPILER_ID} compiler")
if(MSVC)
    message("MSVC version: ${MSVC_VERSION}")
    message("MSVC toolset version: ${MSVC_TOOLSET_VERSION}")
    target_compile_options(${PROJECT_NAME} PRIVATE /FAc)
endif()

target_link_libraries(${PROJECT_NAME} PRIVATE utils_library game_library)

# tests
set(PROJECT_TESTS ${PROJECT_NAME}_tests)
add_executable(
    ${PROJECT_TESTS}
    src/tests/main.cpp
)
target_link_libraries(${PROJECT_TESTS} PRIVATE game_library utils_library)
target_include_directories(${PROJECT_TESTS} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/src)

message("-------------- Compiler flags: ${CMAKE_CXX_FLAGS} --------------")
