#include "unity.h"

#include "msg_core.h"
#include "msg_mqtt.h"
#include "msg_gcp_mqtt.h"

char * dummyJwt(void) 
{
    return NULL;
}

char * createJwt(char *txt) 
{
    return "1234";
} 

void dummy(void)
{

}
void test_msg_gcp_mqtt_createGcpClient(void)
{
    messagingClient_t msgClient;
    gcp_ctx_t ctx;
    ctx.host = "1.1.1.1";
    msgClient.ctx = &ctx;
    //msg_core_createMessagingClient(&msgClient);

    msg_mqtt_t mqtt = {
        .init = &dummy,
        .start = &dummy,
        .publish = &dummy,
        .subscribe = &dummy
    };

    gcpSettings_t settings = {
        .host = "mqtt.googleapis.com",
        .port = 8883,
        .clientId = "projects/phev-db3fa/locations/us-central1/registries/my-registry/devices/my-device",
        .device = "my-device",
        .createJwt = createJwt,
        .mqtt = &mqtt,
        .projectId = "phev-db3fa",
        .eventTopic = "/devices/my-device/events",
        .stateTopic = "my-device-state"
    
    };
    
    messagingClient_t * client = msg_gcp_createGcpClient(settings);
    TEST_ASSERT_NOT_NULL(client);
    //TEST_ASSERT_EQUAL_STRING((const char *) "1.1.1.1", ((gcp_ctx_t *) client->ctx)->host);
}