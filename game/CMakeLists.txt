cmake_minimum_required(VERSION 3.15)
project(game)

file(GLOB_RECURSE source_list
    "${CMAKE_CURRENT_LIST_DIR}/src/*.cpp")

file(GLOB_RECURSE header_list
    "${CMAKE_CURRENT_LIST_DIR}/src/*.h")

add_executable(${PROJECT_NAME} ${source_list} ${header_list} )

set (source "${CMAKE_CURRENT_LIST_DIR}/resources")
set (destination "${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/resources")

add_custom_command(
    TARGET ${PROJECT_NAME} PRE_BUILD
    COMMAND ${CMAKE_COMMAND} -E create_symlink ${source} ${destination}
    #COMMAND ${CMAKE_COMMAND} -E copy ${source} ${destination}
    DEPENDS ${destination}
    COMMENT "symbolic link resources folder from ${source} => ${destination}")


target_link_directories(${PROJECT_NAME}
    PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>
    PRIVATE src)

target_include_directories(${PROJECT_NAME} PUBLIC
    #${ENTT_INCLUDE_DIR}
    #${NUKLEAR_INCLUDE_DIR}
    )
target_link_libraries(${PROJECT_NAME} vubi)

