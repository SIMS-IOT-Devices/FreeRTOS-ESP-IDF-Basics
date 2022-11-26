// Console initiation

#include <stdio.h>
#include <string.h>
#include "esp_system.h"
#include "esp_console.h"
#include "nvs.h"
#include "nvs_flash.h"

#define PROMPT_STR CONFIG_IDF_TARGET

void app_main(void)
{
    nvs_flash_init();
    esp_console_register_help_command();

    // REPL (Read-Evaluate-Print-Loop) environment
    esp_console_repl_t *repl = NULL;
    esp_console_repl_config_t repl_config = ESP_CONSOLE_REPL_CONFIG_DEFAULT();
    repl_config.prompt = PROMPT_STR ">";
    esp_console_dev_uart_config_t hw_config = ESP_CONSOLE_DEV_UART_CONFIG_DEFAULT();
    esp_console_new_repl_uart(&hw_config, &repl_config, &repl);
    esp_console_start_repl(repl);
}