add_executable(main geometrydashworld.hpp geometrydashworld.cpp)
set_property(TARGET main PROPERTY CXX_STANDARD 20)
target_include_directories(main 
        PUBLIC
        "${CMAKE_CURRENT_SOURCE_DIR}/"
        )
target_link_libraries(main PUBLIC sgengine)
#For linux/macos - Link to the current folders libs
set_target_properties(main PROPERTIES LINK_FLAGS "-Wl,-rpath,./libs")
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