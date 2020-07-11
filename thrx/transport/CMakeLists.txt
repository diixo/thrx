
set (SOURCE_LIB_THRX_TRANSPORT
   TTransportException.cpp
   #TBufferTransports.cpp 
)

add_library (lib_thrx_transport STATIC ${SOURCE_LIB_THRX_TRANSPORT})
