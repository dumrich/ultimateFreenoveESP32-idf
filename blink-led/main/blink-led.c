#include <stdio.h>

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

#include "esp_log.h"

void app_main(void)
{
    char* ourTaskName = pcTaskGetName(NULL);

    ESP_LOGI(ourTaskName, "Hello, Starting Up\n");
    while(1) {
        ESP_LOGI(ourTaskName, "Hello, Starting Up\n");
        vTaskDelay(1000);
    }
}
