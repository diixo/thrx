
set (SOURCE_LIB_THRX
   TOutput.cpp 
   TApplicationException.cpp 
)

add_library (lib_thrx STATIC ${SOURCE_LIB_THRX})


# Sub-directories where more CMakeLists.txt exist
#add_subdirectory (agent)
add_subdirectory (concurrency)
add_subdirectory (async)
add_subdirectory (protocol)
add_subdirectory (windows)
add_subdirectory (transport)
add_subdirectory (test)
