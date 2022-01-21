add_executable(main main.cpp)
set_property(TARGET main PROPERTY CXX_STANDARD 20)
target_include_directories(main PUBLIC "/Library/Frameworks/SDL2.framework/Headers")
target_link_libraries(main PUBLIC sgengine)