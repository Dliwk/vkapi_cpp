cmake_minimum_required(VERSION 3.16)
project(vkapi
        VERSION 0.1.0
        LANGUAGES CXX)

add_subdirectory(thirdparty)

set(CMAKE_CXX_STANDARD 17)
file(GLOB_RECURSE LIB_SOURCES
        "include/*.h"
        "src/*.cpp")
add_library(${PROJECT_NAME} STATIC ${LIB_SOURCES})

find_package(PkgConfig REQUIRED)
pkg_check_modules(JSONCPP jsoncpp)

if (!JSONCPP_FOUND)
    message(FATAL_ERROR "JsonCpp not found!")
endif()


target_include_directories(${PROJECT_NAME} PRIVATE include)
target_include_directories(${PROJECT_NAME} PUBLIC ${THIRDPARTY_INCLUDE_DIRS})
target_include_directories(${PROJECT_NAME} PUBLIC ${JSONCPP_INCLUDE_DIRS})

target_link_libraries(${PROJECT_NAME} ${THIRDPARTY_STATIC_LIBS} ${JSONCPP_LIBRARIES})

add_subdirectory(examples)
