
set (SOURCE_LIB_THRX_ASYNC
   TAsyncChannel.cpp
   TAsyncProtocolProcessor.cpp 
   TConcurrentClientSyncInfo.cpp 
)

add_library (lib_thrx_async STATIC ${SOURCE_LIB_THRX_ASYNC})
