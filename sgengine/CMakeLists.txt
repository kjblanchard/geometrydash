message(STATUS HELLOS)
add_library(
    sgengine SHARED
    initialize_audio.cpp
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

target_include_directories(sgengine PUBLIC "/Library/Frameworks/SDL2.framework/Headers" 
"./" 
"/Library/Frameworks/"
"/Library/Frameworks/FMOD Programmers API/api/studio/inc/"
"/Library/Frameworks/FMOD Programmers API/api/core/inc/")
set_property(TARGET sgengine PROPERTY CXX_STANDARD 20)
target_link_libraries(sgengine
PUBLIC
libfmod
libfmodstudio
)
# target_link_libraries(sgengine PUBLIC 
# "/Library/Frameworks/FMOD Programmers API/api/studio/lib/libfmodstudio.dylib")
# target_include_directories(sgengine PUBLIC "./")