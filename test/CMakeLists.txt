add_executable(msg_core_app
    msg_core_runner.c
)

target_link_libraries(msg_core_app
    msg_core
    Unity
)

add_test(test_msg_core msg_core_app)