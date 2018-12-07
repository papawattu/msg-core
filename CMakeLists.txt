project("Message Core" C)
cmake_minimum_required(VERSION 3.0)

add_library(msg_core STATIC
    msg_core/src/msg_core.c
    msg_core/src/msg_gcp_mqtt.c
    msg_core/src/msg_mqtt.c
    msg_core/src/msg_pipe_splitter.c
    msg_core/src/msg_pipe.c 
    msg_core/src/msg_tcpip.c 
    msg_core/src/msg_utils.c
)

include(CTest)

add_subdirectory(external) 

add_subdirectory(test)

target_include_directories(msg_core PUBLIC include)
