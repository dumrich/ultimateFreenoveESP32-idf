#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"

int ledPins[] = {15, 2, 0, 4, 5, 18, 19, 21, 22, 23};
int ledCounts;

void led_task(void *pvParameter) {
    while (1) {
        for(int i = 0; i < sizeof(ledPins)/sizeof(int); i++) {
            gpio_set_level(ledPins[i], 1);  // Turn on the LED
            vTaskDelay((10 + i * 10) / portTICK_PERIOD_MS);  // Delay for 10ms
            gpio_set_level(ledPins[i], 0);  // Turn off the LED
        }
        for(int i = sizeof(ledPins)/sizeof(int) - 1; i >= 0; i--) {
            gpio_set_level(ledPins[i], 1);  // Turn on the LED
            vTaskDelay(100 / portTICK_PERIOD_MS);  // Delay for 10ms
            gpio_set_level(ledPins[i], 0);  // Turn off the LED
        }
    }
}

void app_main() {
    for(int i = 0; i < sizeof(ledPins)/sizeof(int); i++) {
        gpio_set_direction(ledPins[i], GPIO_MODE_OUTPUT);
    }

    xTaskCreate(led_task, "led_task", 2048, NULL, 5, NULL); // Pass the argument
}
