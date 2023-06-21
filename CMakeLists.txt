cmake_minimum_required(VERSION 3.0)
project(InstaBrute)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -g")

# Source files
set(SRCS src/main.cpp)

# Output directory
set(OUTPUT_DIR ${CMAKE_BINARY_DIR}/build)
file(MAKE_DIRECTORY ${OUTPUT_DIR})

# Build target
add_executable(${PROJECT_NAME} ${SRCS})
target_link_libraries(${PROJECT_NAME} ${SDL2_LIBRARIES} ${LIBS})

# Link against the WinINet library on Windows
if (WIN32)
    target_link_libraries(${PROJECT_NAME} wininet)
endif ()

set_target_properties(${PROJECT_NAME} PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${OUTPUT_DIR})

# Clean target
add_custom_target(clean-all
        COMMAND ${CMAKE_COMMAND} -E remove_directory ${OUTPUT_DIR}
        COMMAND ${CMAKE_COMMAND} -E remove ${CMAKE_BINARY_DIR}/CMakeCache.txt
        COMMAND ${CMAKE_COMMAND} -E remove ${CMAKE_BINARY_DIR}/cmake_install.cmake
        COMMAND ${CMAKE_COMMAND} -E remove ${CMAKE_BINARY_DIR}/Makefile
        COMMAND ${CMAKE_COMMAND} -E remove ${CMAKE_BINARY_DIR}/CMakeFiles
        WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
        )