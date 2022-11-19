// Read serial data from the serial port

#include <stdio.h>
#include <string.h>
#include "driver/uart.h"

void app_main(void)
{
    char chr[10];
    while(1){
        printf("\nEnter Data : ");
        scanf("%9s", chr);
        printf("\nData entered : %s\n", chr);
        strcpy(chr, "");
        vTaskDelay(5000 / portTICK_RATE_MS);
    }
}