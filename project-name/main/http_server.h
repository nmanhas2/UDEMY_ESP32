/////////////////////////////////////////////////////////////////////////////

///	Purpose: HTTP configuration header file

/// Author: Nubal Manhas

/////////////////////////////////////////////////////////////////////////////

#include "esp_mac.h"

#define OTA_UPDATE_PENDING       0
#define OTA_UPDATE_SUCCESSFUL    1
#define OTA_UPDATE_FAILED       -1

/*
    Connection status for WiFi
*/
typedef enum http_server_wifi_connect_status
{
    NONE = 0,
    HTTP_WIFI_STATUS_CONNECTING,
    HTTP_WIFI_STATUS_CONNECT_FAILED,
    HTTP_WIFI_STATUS_CONNECT_SUCCESS,
    HTTP_WIFI_STATUS_DISCONNECT
} http_server_wifi_connect_status_e;

/*
    Messages for HTTP monitor
*/
typedef enum http_Server_message
{
    HTTP_MSG_WIFI_CONNECT_INIT = 0,
    HTTP_MSG_WIFI_CONNECT_SUCCESS,
    HTTP_MSG_WIFI_CONNECT_FAIL,
    HTTP_MSG_WIFI_USER_DISCONNECT,
    HTTP_MSG_OTA_UPDATE_SUCCESSFUL,
    HTTP_MSG_OTA_UPDATE_FAILED,
    HTTP_MSG_TIME_SERVICE_INITIALIZED,
} http_server_message_e;

/*
    Structure for the message queue
*/
typedef struct http_server_queue_message
{
    http_server_message_e msgID;
} http_server_queue_message_t;

/*
    Sends a message to the queue
    msgID = message ID from the htto_server_message_e enum
    return = pdTRUE if an itrm was successfully sent to the queue, otherwise pdFALSE
*/
BaseType_t http_server_monitor_send_message(http_server_message_e msgID);

/*
    Starts the HTTP server
*/
void http_server_start(void);

/*
    Stop the HTTP server
*/
void http_server_stop(void);

/*
    Timer callback wich calls esp restart upon successful formware update
*/
void http_server_fw_update_reset_callback(void *arg);