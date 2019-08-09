project("Message Core" C)
cmake_minimum_required(VERSION 3.0)

set (CMAKE_C_STANDARD 11)

add_library(msg_core STATIC
    src/msg_core.c
    src/msg_gcp_mqtt.c
    src/msg_mqtt.c
    src/msg_pipe_splitter.c
    src/msg_pipe.c 
    src/msg_tcpip.c 
    src/msg_utils.c
	src/msg_mqtt_paho.c
)

option (LOG_LEVEL "Log level" 0)
include(CTest)

add_subdirectory(external) 

add_subdirectory(test)

#target_link_libraries(msg_core "${PAHO_LIB}")
target_include_directories(msg_core PUBLIC include)

install(TARGETS msg_core DESTINATION lib)
install(FILES 
	include/msg_core.h 
	include/msg_gcp_mqtt.h
	include/msg_mqtt.h
	include/msg_pipe_splitter.h
	include/msg_pipe.h
	include/msg_tcpip.h
	include/msg_utils.h
	include/msg_mqtt_paho.h
	DESTINATION include)
