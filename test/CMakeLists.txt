
<<<<<<< HEAD
find_library(PAHO_LIB paho-mqtt3c-static)
find_library(UNITY_LIB Unity REQUIRED)

IF("${PAHO_LIB}")
	MESSAGE("All good")
ELSE()
	MESSAGE("no PAHO_LIB")
ENDIF()
=======
#find_library(PAHO_LIB paho-mqtt3c-static)
find_package(unity)
>>>>>>> c36a9f5512e69a43d67eb8a750a1cf969aa12e6a

add_executable(test_msg_core
    msg_core_runner.c
)

target_link_libraries(test_msg_core
    msg_core
<<<<<<< HEAD
    ${UNITY_LIB}
=======
    unity
>>>>>>> c36a9f5512e69a43d67eb8a750a1cf969aa12e6a
    ${PAHO_LIB}
)

add_test(test_msg_core test_msg_core)