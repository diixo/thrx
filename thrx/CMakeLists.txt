
LIST (APPEND SOURCE_THRX 
   TOutput.cpp 
)

# Sub-directories where more CMakeLists.txt exist
add_subdirectory (agent)
add_subdirectory (concurrency)
add_subdirectory (windows)
add_subdirectory (test)
