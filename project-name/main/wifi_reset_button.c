/////////////////////////////////////////////////////////////////////////////

///	Purpose: Wifi Reset Button Configuration

/// Author: Nubal Manhas

/////////////////////////////////////////////////////////////////////////////

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/semphr.h"
#include "driver/gpio.h"
#include "esp_log.h"

#include "tasks_common.h"
#include "wifi_app.h"
#include "wifi_reset_button.h"

static const char TAG[] = "wifi_reset_button";

SemaphoreHandle_t wifi_reset_semaphore = NULL;

/*
    ISR handler for the WiFi reset (BOOT) button
    arg = parameter which can be passed to the ISR handler
*/
void IRAM_ATTR wifi_reset_button_isr_handler(void *arg)
{
    xSemaphoreGiveFromISR(wifi_reset_semaphore, NULL);

}

/*
    Wifi reset button task reacts to a BOOT button event by sending a message
    to the WiFi applciation to disconenct from WiFi and clear the saved credentials.
    pvParam = parameter which can be passed to the task
*/
void wifi_reset_button_task(void *pvParam)
{
    for(;;)
    {
        if(xSemaphoreTake(wifi_reset_semaphore, portMAX_DELAY) == pdTRUE)
        {
            ESP_LOGI(TAG, "WIFI RESET BUTTON INTERRUPT OCCURRED");

            //Send a message to disconnect WiFi and clear credentials
            wifi_app_send_message(WIFI_APP_MSG_USER_REQUESTED_STA_DISCONNECT);

            vTaskDelay(2000 / portTICK_PERIOD_MS);

        }
    }
}

void wifi_reset_button_config(void)
{
    //Create the binary semaphore
    wifi_reset_semaphore = xSemaphoreCreateBinary();

    //Configure the button and set the direction 
    esp_rom_gpio_pad_select_gpio(WIFI_RESET_BUTTON);
    gpio_set_direction(WIFI_RESET_BUTTON, GPIO_MODE_INPUT);

    //Enable interrupt
    gpio_set_intr_type(WIFI_RESET_BUTTON, GPIO_INTR_NEGEDGE);

    //Create the Wifi Reset button task
    xTaskCreatePinnedToCore(&wifi_reset_button_task, "wifi_reset_button", WIFI_RESET_BUTTON_TASK_STACK_SIZE, NULL, WIFI_RESET_BUTTON_TASK_PRIORITY, NULL, WIFI_RESET_BUTTON_TASK_CORE_ID);

    //Install GPIO ISR service
    gpio_install_isr_service(ESP_INTR_FLAG_DEFAULT);

    //Attach the interrupt service routine
    gpio_isr_handler_add(WIFI_RESET_BUTTON, wifi_reset_button_isr_handler, NULL);
}

