//Libreria freertos
//https://docs.espressif.com/projects/esp-idf/en/latest/esp32/api-reference/system/freertos.html
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

//Para configurar GPIO
//https://docs.espressif.com/projects/esp-idf/en/latest/esp32/api-reference/peripherals/gpio.html
#include "driver/gpio.h"

//Archivo de configuracion creado durante la compilacion
#include "sdkconfig.h"

//Libreria Logging
//https://docs.espressif.com/projects/esp-idf/en/latest/esp32/api-reference/system/log.html
#define LOG_LOCAL_LEVEL ESP_LOG_VERBOSE
#include "esp_log.h"

//puede editar Kconfig.projbuild para elegir el GPIO para parpadear,
#define PIN CONFIG_BLINK_GPIO

//O puede establecer un número GPIO directamente aquí.
//#define PIN 25

//static const char *TAG = "Led_blink"; //tag para el log por consola

void conf_led() {
	//Selecciono el GPIO donde esta conectado el LED
	gpio_pad_select_gpio(PIN);
	/* Establecer el GPIO como una salida push / pullt */
	gpio_set_direction(PIN, GPIO_MODE_OUTPUT);
}

void app_main(void) {
	conf_led();

	uint8_t nivel=false; //Estado que se asignara al led 0=apagado; 1=encendido
	//unsigned char nivel = false; //TAMBIEN FUNCIONARA

	uint16_t periodo=1000; //ms entre cada cambio de estado
	//unsigned int periodo = 1000; //TAMBIEN FUNCIONARA
	while (1) {
		ESP_LOGI(pcTaskGetName(NULL), "Pongo la GPIO_%d en %i\n", PIN, nivel);
		gpio_set_level(PIN, nivel); //LLevo el PIN al valor nivel
		nivel = !nivel; //invierto el valor de nivel

		//retardo 1000ms
		vTaskDelay(periodo / portTICK_PERIOD_MS);
	}
}
