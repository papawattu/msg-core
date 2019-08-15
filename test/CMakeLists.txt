find_package(unity)

add_executable(test_msg_core
    msg_core_runner.c
)

target_link_libraries(test_msg_core
    msg_core
    unity
    ${PAHO_LIB}
    pthread
)

add_test(test_msg_core test_msg_core)