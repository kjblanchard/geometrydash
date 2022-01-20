
add_executable(main main.cpp)
target_include_directories(main PUBLIC "/Library/Frameworks/SDL2.framework/Headers")
target_link_libraries(main PUBLIC sgengine)