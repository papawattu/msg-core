#include "unity.h"

#include "msg_core.h"
#include "msg_utils.h"
#include "msg_mqtt_paho.h"
#include "logger.h"

#define TOPIC "topic"
#define MSG_ID 1234
#define DATA_LEN 4


void test_msg_mqtt_paho_create_mqtt_paho_client_not_null(void)
{
    mqttPahoSettings_t settings = {
        .uri = "test.mqtt.com",
        .clientId = "client",
        .username = "user",
        .password = "password",
        .incomingTopic = NULL,
        .outgoingTopic = NULL,
    };

    messagingClient_t * client = msg_mqtt_paho_createMqttPahoClient(settings);
    
    TEST_ASSERT_NOT_NULL(client);
    
}
void test_msg_mqtt_paho_create_mqtt_paho_client_paho_client_not_null(void)
{
    mqttPahoSettings_t settings = {
        .uri = "test.mqtt.com",
        .clientId = "client",
        .username = "user",
        .password = "password",
        .incomingTopic = NULL,
        .outgoingTopic = NULL,
    };

    messagingClient_t * client = msg_mqtt_paho_createMqttPahoClient(settings);
    
    TEST_ASSERT_NOT_NULL(((mqtt_paho_ctx_t *) client->ctx)->client);
    
}
void test_msg_mqtt_paho_connect(void)
{
    mqttPahoSettings_t settings = {
        .uri = "tcp://iot.eclipse.org:1883",
        .clientId = "client",
        .username = "user",
        .password = "password",
        .incomingTopic = NULL,
        .outgoingTopic = NULL,
    };

    messagingClient_t * client = msg_mqtt_paho_createMqttPahoClient(settings);
    
    int ret = client->connect(client);

    TEST_ASSERT_EQUAL(0,ret);
    
}
void test_msg_mqtt_paho_publish(void)
{
    mqttPahoSettings_t settings = {
        .uri = "tcp://iot.eclipse.org:1883",
        .clientId = "client",
        .username = "user",
        .password = "password",
        .incomingTopic = NULL,
        .outgoingTopic = NULL,
    };

    const static uint8_t TEST_DATA[] = "Hello";
    message_t * message = msg_utils_createMsgTopic("test",TEST_DATA, sizeof(TEST_DATA));
    messagingClient_t * client = msg_mqtt_paho_createMqttPahoClient(settings);
    
    int ret = client->connect(client);

    client->publish(client, message);

    TEST_ASSERT_EQUAL(0,ret);
    
} /*
void test_msg_mqtt_paho_publish(void)
{
    mqttPahoSettings_t settings = {
        .uri = "tcp://iot.eclipse.org:1883",
        .clientId = "client",
        .username = "user",
        .password = "password",
    };

    const static uint8_t TEST_DATA[] = "Hello";
    message_t * message = msg_utils_createMsgTopic("test",TEST_DATA, sizeof(TEST_DATA));
    messagingClient_t * client = msg_mqtt_paho_createMqttPahoClient(settings);
    
    int ret = client->connect(client);

    client->publish(client, message);

    TEST_ASSERT_EQUAL(0,ret);
    
} */