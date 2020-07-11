
add_executable (app_test Tests.cpp)

target_link_libraries (
   app_test 
   lib_thrx_async 
   lib_thrx_concurrency 
   lib_thrx_protocol 
   lib_thrx_transport 
   lib_thrx_windows 
   lib_thrx
)
