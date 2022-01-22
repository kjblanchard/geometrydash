#Random status message
message(STATUS "Starting Engine Cmake..")

#Add all of our source files and headers to this library.
file(GLOB FILES "sgengine/**/*.?pp")
add_library(sgengine SHARED ${FILES})

#Define libraries that we depend on, shared is dynamic linking.  Imported needs a specific location.
set(libnames libfmod libfmodstudio SDL2)
foreach(library ${libnames})
        add_library(${library} SHARED IMPORTED)
endforeach()


#Add absolute paths to link to for development.
foreach(library ${libnames})
        set_target_properties( ${library}
                                PROPERTIES IMPORTED_LOCATION
                                /Users/kevin.blanchard/git/personal/c/geometry_dash/sgengine/libs/${library}.dylib
                                )
endforeach()

#Add relative paths to link to for distribution.
foreach(library ${libnames})
        set_target_properties(${library} PROPERTIES LINK_FLAGS "-Wl,-rpath,./libs")
endforeach()

#Include directories for the sgengine.
target_include_directories(sgengine 
PUBLIC
"/Library/Frameworks/FMOD Programmers API/api/studio/inc/"
"/Library/Frameworks/FMOD Programmers API/api/core/inc/"
"${CMAKE_CURRENT_SOURCE_DIR}/"
)
#Set c++20 standard for this.
set_property(TARGET sgengine PROPERTY CXX_STANDARD 20)

#Actually create the links.
target_link_libraries(sgengine PUBLIC ${libnames})

# Copy files in the build folder so that we can have quick iterations and testing / building / distribution WOW DEVOPS
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