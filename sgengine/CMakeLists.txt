message(STATUS HELLOS)
add_library(
    sgengine SHARED
    initialize_audio.cpp
    core/Point.hpp
    core/World.hpp
    core/World.cpp
)
# Add tripartite so Libraries
add_library(libfmod
            SHARED
            IMPORTED )

 # The Absolute Path of Naming Third Party Library
 set_target_properties( libfmod
                        PROPERTIES IMPORTED_LOCATION
                        /Users/kevin.blanchard/git/personal/c/geometry_dash/sgengine/libs/libfmod.dylib
                        )
add_library(libfmodstudio
            SHARED
            IMPORTED )

 # The Absolute Path of Naming Third Party Library
 set_target_properties( libfmodstudio
                        PROPERTIES IMPORTED_LOCATION
                        /Users/kevin.blanchard/git/personal/c/geometry_dash/sgengine/libs/libfmodstudio.dylib
                        )
add_library(sdl
            SHARED
            IMPORTED )

 # The Absolute Path of Naming Third Party Library
 set_target_properties( sdl
                        PROPERTIES IMPORTED_LOCATION
                        /Users/kevin.blanchard/git/personal/c/geometry_dash/sgengine/libs/SDL2.dylib
                        )


target_include_directories(sgengine 
PUBLIC 
"/Library/Frameworks/SDL2.framework/Headers" 
"/Library/Frameworks/FMOD Programmers API/api/studio/inc/"
"/Library/Frameworks/FMOD Programmers API/api/core/inc/"
"sgengine/"
)
set_property(TARGET sgengine PROPERTY CXX_STANDARD 20)
target_link_libraries(sgengine
PUBLIC
libfmod
libfmodstudio
sdl
)
add_custom_command(
        TARGET sgengine POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy
                ${CMAKE_SOURCE_DIR}/sgengine/libs/libfmod.dylib
                ${CMAKE_BINARY_DIR}/${CMAKE_PROJECT_NAME}/libs/libfmod.dylib)
add_custom_command(
        TARGET sgengine POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy
                ${CMAKE_SOURCE_DIR}/sgengine/libs/libfmodstudio.dylib
                ${CMAKE_BINARY_DIR}/${CMAKE_PROJECT_NAME}/libs/libfmodstudio.dylib)
add_custom_command(
        TARGET sgengine POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy
                ${CMAKE_SOURCE_DIR}/sgengine/libs/SDL2.dylib
                ${CMAKE_BINARY_DIR}/${CMAKE_PROJECT_NAME}/libs/SDL2.dylib)