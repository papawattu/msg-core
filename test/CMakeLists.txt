
#find_library(PAHO_LIB paho-mqtt3c-static)
find_package(unity)

add_executable(test_msg_core
    msg_core_runner.c
)

target_link_libraries(test_msg_core
    msg_core
    unity
    ${PAHO_LIB}
)

add_test(test_msg_core test_msg_core)