#include <stdio.h>
#include "sign_api.h"

#define EXAMPLE_PRODUCT_KEY     "a1X2bEn****"
#define EXAMPLE_PRODUCT_SECRET  "7jluWm1zql7b****"
#define EXAMPLE_DEVICE_NAME     "example1"
#define EXAMPLE_DEVICE_SECRET   "ga7XA6KdlEeiPXQPpRbAjOZXwG8y****"


int main(){
    printf("Hello, world!!!\n");
    iotx_dev_meta_info_t meta_info;
    iotx_sign_mqtt_t sign_mqtt;

    memset(&meta_info, 0, sizeof(iotx_dev_meta_info_t));

    printf("product_key: ");
    scanf("%s", &(meta_info.product_key));
    printf("product_secret: ");
    scanf("%s", &(meta_info.product_secret));
    printf("device_name: ");
    scanf("%s", &(meta_info.device_name));
    printf("device_secret: ");
    scanf("%s", &(meta_info.device_secret));

    //下面的代码是将上面静态定义的设备身份信息赋值给meta_info
    //memcpy(meta_info.product_key, EXAMPLE_PRODUCT_KEY, strlen(EXAMPLE_PRODUCT_KEY));
    //memcpy(meta_info.product_secret, EXAMPLE_PRODUCT_SECRET, strlen(EXAMPLE_PRODUCT_SECRET));
    //memcpy(meta_info.device_name, EXAMPLE_DEVICE_NAME, strlen(EXAMPLE_DEVICE_NAME));
    //memcpy(meta_info.device_secret, EXAMPLE_DEVICE_SECRET, strlen(EXAMPLE_DEVICE_SECRET));

    //调用签名函数，生成MQTT连接时需要的各种数据
    IOT_Sign_MQTT(IOTX_CLOUD_REGION_SHANGHAI, &meta_info, &sign_mqtt);

    printf("==== Sign ====\n");
    printf("Hostname: %s\n", sign_mqtt.hostname);
    printf("Port: %d\n", sign_mqtt.port);
    printf("Username: %s\n", sign_mqtt.username);
    printf("Password: %s\n", sign_mqtt.password);
    printf("ClientId: %s\n", sign_mqtt.clientid);
    printf("done!\n");

    return 0;
}