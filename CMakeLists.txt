cmake_minimum_required(VERSION 3.20.0)

project(SearchEngine)

set (CMAKE_CXX_STANDARD 17)

set(EXECUTABLE ${PROJECT_NAME})

set(INC_DIR "${CMAKE_CURRENT_SOURCE_DIR}/inc")
file(GLOB INC_FILES "${INC_DIR}/*.h")
include_directories(${INC_DIR})

set(SRC_DIR "${CMAKE_CURRENT_SOURCE_DIR}/src")
file(GLOB SRC_FILES "${SRC_DIR}/*.cpp")

include_directories("${CMAKE_CURRENT_SOURCE_DIR}/lib/boost_1_85_0")

add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/lib/libpqxx-7.8.1" libpqxx_build)

add_executable(${EXECUTABLE} ${SRC_FILES})

target_link_libraries(${EXECUTABLE} pqxx)

add_custom_command(
        TARGET SearchEngine POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy
                ${CMAKE_SOURCE_DIR}/config.ini
                ${CMAKE_CURRENT_BINARY_DIR}/config.ini
)