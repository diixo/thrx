
set (SOURCE_LIB_THRX_CONCURRENCY
   Monitor.cpp 
   Mutex.cpp 
   Thread.cpp 
   ThreadFactory.cpp 
   ThreadManager.cpp 
   TimerManager.cpp 
)

add_library (lib_thrx_concurrency STATIC ${SOURCE_LIB_THRX_CONCURRENCY})
