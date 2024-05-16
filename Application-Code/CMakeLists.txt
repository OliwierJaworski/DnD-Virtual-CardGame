cmake_minimum_required(VERSION 3.0.0)

add_compile_definitions(debug)

add_executable(DND-ASSIGNMENT main.c 
               dependencies/Data-Related.c
               dependencies/Data-Related.h
               dependencies/Application-Related.c
               dependencies/Application-Related.h
               #dependencies/Player-Related.c
               dependencies/Player-Related.h
               dependencies/Debug-Related.c
               dependencies/Debug-Related.h)
               
if (WIN32)
endif (WIN32)

if (UNIX)
    find_package(CURL REQUIRED)
    target_link_libraries(DND-ASSIGNMENT CURL::libcurl ) 
    target_link_libraries(DND-ASSIGNMENT m)
endif (UNIX)







