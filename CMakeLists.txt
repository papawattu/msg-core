project("Message Core" C)
cmake_minimum_required(VERSION 3.0)


OPTION(BUILD_TEST "Build test files")
OPTION(MQTT_PAHO "Enable Paho MQTT")
set (CMAKE_C_STANDARD 11)

IF(${MQTT_PAHO})
	SET(MQTT_PAHO_SRC src/msg_mqtt_paho.c)
ENDIF()

add_library(msg_core STATIC
    src/msg_core.c
    src/msg_gcp_mqtt.c
    src/msg_mqtt.c
    src/msg_pipe_splitter.c
    src/msg_pipe.c 
    src/msg_tcpip.c 
    src/msg_utils.c
	${MQTT_PAHO_SRC}
)

IF(${BUILD_TEST})
	find_library(UNITY unity)
    include(CTest)
	add_subdirectory(test)
ENDIF()

target_include_directories(msg_core PUBLIC include)

install(TARGETS msg_core DESTINATION lib)
install(FILES 
	inlcude/logger.h
	include/msg_core.h 
	include/msg_gcp_mqtt.h
	include/msg_mqtt.h
	include/msg_pipe_splitter.h
	include/msg_pipe.h
	include/msg_tcpip.h
	include/msg_utils.h
	include/msg_mqtt_paho.h
	DESTINATION include)
