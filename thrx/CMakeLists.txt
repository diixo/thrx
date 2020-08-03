
set (SOURCE_LIB_THRX
   TOutput.cpp 
   TApplicationException.cpp 
)

add_library (lib_thrx STATIC ${SOURCE_LIB_THRX})

# giving it a proper look in MSVS
source_group("Header Files\\concurrency" REGULAR_EXPRESSION ".*\\.h$")
source_group("Source Files\\concurrency" REGULAR_EXPRESSION "*.*\\.cpp$")
source_group("Header Files\\async" REGULAR_EXPRESSION "*.*\\.h$")
source_group("Source Files\\async" REGULAR_EXPRESSION "*.*\\.cpp$")
source_group("Header Files\\protocol" REGULAR_EXPRESSION "*.*\\.h$")
source_group("Source Files\\protocol" REGULAR_EXPRESSION "*.*\\.cpp$")
source_group("Header Files\\windows" REGULAR_EXPRESSION "*.*\\.h$")
source_group("Source Files\\windows" REGULAR_EXPRESSION "*.*\\.cpp$")
source_group("Header Files\\transport" REGULAR_EXPRESSION ".*transport.*\\*.h$")
source_group("Source Files\\transport" REGULAR_EXPRESSION ".*transport.*\\*.cpp$")

source_group("Header Files\\transport" REGULAR_EXPRESSION "transport\\.h$")
source_group("Source Files\\transport" REGULAR_EXPRESSION "transport\\.cpp$")

source_group("Header Files\\test" REGULAR_EXPRESSION "*.*\\.h$")
source_group("Source Files\\test" REGULAR_EXPRESSION "*.*\\.cpp$")


# Sub-directories where more CMakeLists.txt exist
#add_subdirectory (agent)
add_subdirectory (concurrency)
add_subdirectory (async)
add_subdirectory (protocol)
add_subdirectory (windows)
add_subdirectory (transport)
add_subdirectory (test)
