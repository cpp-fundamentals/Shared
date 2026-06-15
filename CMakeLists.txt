cmake_minimum_required(VERSION 3.20)

project(SharedPtr VERSION 0.0.01 LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

message("======SHARED REALIZ BUILDING=========")
option(BUILD_APP "Build executable example")

add_library(${PROJECT_NAME}_lib INTERFACE)


target_include_directories(${PROJECT_NAME}_lib INTERFACE 
                ${CMAKE_CURRENT_SOURCE_DIR}/inc
)


if(BUILD_APP)
    add_executable(${PROJECT_NAME}_app ${CMAKE_CURRENT_SOURCE_DIR}/examples/main.cpp)
    target_link_libraries(${PROJECT_NAME}_app
        PRIVATE SharedPtr_lib
    )

endif()