cmake_minimum_required(VERSION 3.21.1)
project(geometrydash VERSION 0.0.1)
include_directories(
"/Library/Frameworks/SDL2.framework/Headers" 
)

add_subdirectory(sgengine)
add_subdirectory(geometrydash)
