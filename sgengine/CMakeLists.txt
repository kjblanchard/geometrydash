#Random status message
message(STATUS "Starting Engine Cmake..")

#Add all of our source files and headers to this library.
file(GLOB FILES "sgengine/**/*.?pp")
add_library(sgengine SHARED ${FILES})

#Define library names / references to their link files that we depend on, shared is dynamic linking.  Imported needs a specific location.
set(libnames libfmod libfmodstudio SDL2 SDL2_image)
foreach(library ${libnames})
        add_library(${library} SHARED IMPORTED)
endforeach()

#Set a variable for our external library paths
set (libpaths 
        "/Library/Frameworks/FMOD Programmers API/api/studio/inc/"
        "/Library/Frameworks/FMOD Programmers API/api/core/inc/"
        )

#Add absolute paths to link to for development.
foreach(library ${libnames})
        set_target_properties( ${library}
                                PROPERTIES IMPORTED_LOCATION
                                /usr/local/lib/${library}.dylib
                                )
endforeach()

#Add relative paths to link to for distribution.
foreach(library ${libnames})
        set_target_properties(${library} PROPERTIES LINK_FLAGS "-Wl,-rpath,./libs")
endforeach()

#Include directories for the sgengine.
target_include_directories(sgengine 
        PUBLIC
        ${libpaths}
        "${CMAKE_CURRENT_SOURCE_DIR}/"
        )
#Set c++20 standard for this.
set_property(TARGET sgengine PROPERTY CXX_STANDARD 20)

#Actually create the links.
target_link_libraries(sgengine PUBLIC ${libnames})

#POST BUILD - Copy the libraries required for this project from my PC to the build folder for easy distribution.  For some reason, for each wasn't working.
add_custom_command(
        TARGET sgengine POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy
                /usr/local/lib/libfmod.dylib
                ${CMAKE_BINARY_DIR}/${CMAKE_PROJECT_NAME}/lib/libfmod.dylib)
add_custom_command(
        TARGET sgengine POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy
                /usr/local/lib/libfmodstudio.dylib
                ${CMAKE_BINARY_DIR}/${CMAKE_PROJECT_NAME}/lib/libfmodstudio.dylib)
add_custom_command(
        TARGET sgengine POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy
                /usr/local/lib/SDL2.dylib
                ${CMAKE_BINARY_DIR}/${CMAKE_PROJECT_NAME}/lib/SDL2.dylib)
add_custom_command(
        TARGET sgengine POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy
                /usr/local/lib/SDL2_image.dylib
                ${CMAKE_BINARY_DIR}/${CMAKE_PROJECT_NAME}/lib/SDL2_image.dylib)
add_custom_command(
        TARGET sgengine POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy
                ${CMAKE_CURRENT_BINARY_DIR}/libsgengine.dylib
                ${CMAKE_BINARY_DIR}/${CMAKE_PROJECT_NAME}/lib/libsgengine.dylib)