
find_library(PAHO_LIB paho-mqtt3c-static)
find_library(UNITY_LIB Unity REQUIRED)

IF("${PAHO_LIB}")
	MESSAGE("All good")
ELSE()
	MESSAGE("no PAHO_LIB")
ENDIF()

add_executable(test_msg_core
    msg_core_runner.c
)

target_link_libraries(test_msg_core
    msg_core
    ${UNITY_LIB}
    ${PAHO_LIB}
)

add_test(test_msg_core test_msg_core)