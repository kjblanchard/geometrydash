add_executable(main main.cpp)
set_property(TARGET main PROPERTY CXX_STANDARD 20)
# target_include_directories(main PUBLIC "/Library/Frameworks/SDL2.framework/Headers")
target_link_libraries(main PUBLIC sgengine)
add_custom_target(build-time-make-directory ALL
    COMMAND ${CMAKE_COMMAND} -E make_directory 
    ${CMAKE_CURRENT_BINARY_DIR}/sfx)
add_custom_command(
        TARGET main POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy
                ${CMAKE_SOURCE_DIR}/geometrydash/sfx/Master.bank
                ${CMAKE_CURRENT_BINARY_DIR}/sfx/Master.bank)
add_custom_command(
        TARGET main POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy
                ${CMAKE_SOURCE_DIR}/geometrydash/sfx/Master.strings.bank
                ${CMAKE_CURRENT_BINARY_DIR}/sfx/Master.strings.bank)