/////////////////////////////////////////////////////////////////////////////

///	Purpose: FreeRTOS task configuration header file 

/// Author: Nubal Manhas

/////////////////////////////////////////////////////////////////////////////

//WiFi application task
#define WIFI_APP_TASK_STACK_SIZE        4096
#define WIFI_APP_TASK_PRIORITY          5
#define WIFI_APP_CORE_ID                0

//HTTP Server Task
#define HTTP_SERVER_TASK_STACK_SIZE     8192
#define HTTP_SERVER_TASK_PRIORITY       4 //one level below WiFi task
#define HTTP_SERVER_TASK_CORE_ID        0

//HTTP Server Monitor Task
#define HTTP_SERVER_MONITOR_STACK_SIZE   4096
#define HTTP_SERVER_MONITOR_PRIORITY    3
#define HTTP_SERVER_MONITOR_CORE_ID     0

//Wifi Reset Button task
#define WIFI_RESET_BUTTON_TASK_STACK_SIZE 2048
#define WIFI_RESET_BUTTON_TASK_PRIORITY   7 //making this highest priority to ensure other tasks are pre-empted when the button task unblocks
#define WIFI_RESET_BUTTON_TASK_CORE_ID    0

//DHT22 Sensor Task
#define DHT22_TASK_STACK_SIZE     4096
#define DHT22_TASK_PRIORITY       1 
#define DHT22_TASK_CORE_ID        0

//SNTP Time Sync Task
#define SNTP_TIME_SYNC_TASK_TASK_SIZE 4096
#define SNTP_TIME_SYNC_TASK_PRIORITY  2
#define SNTP_TIME_SYNC_TASK_CORE_ID   0

//AWS IoT Task
#define AWS_IOT_TASK_STACK_SIZE       9216
#define AWS_IOT_TASK_PRIORITY         6
#define AWS_IOT_TASK_CORE_ID          0