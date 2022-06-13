#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_log.h"
#include "ssd1306.h" //0.96-inch 128*64 dot matrix OLED display
#define tag "SSD1306"

void tarea_ssd1306(void *pvParameter) {
	uint8_t L = 16;	//Numero maximo de caracteres por fila
	char str[L + 1]; //para guardar el string de cada fila
	float v1, v2, v3, v4;
	SSD1306_t dev;
	i2c_master_init(&dev, CONFIG_SDA_GPIO, CONFIG_SCL_GPIO, CONFIG_RESET_GPIO);
	ssd1306_init(&dev, 128, 64);

	ssd1306_clear_screen(&dev, false);
	ssd1306_contrast(&dev, 0xff);

	ssd1306_display_text(&dev, 0, "  VALOR MEDIDO  ", 16, true); //PONGO EL TITULO

	v1 = 0.1234;
	ESP_LOGI(pcTaskGetName(NULL), "V1= %0.4f", v1); //V1 a la consola
	memset(str, ' ', L);					//limpio str
	//sprintf(str, "               ");
	sprintf(str, "V1: %0.4f", v1);	//V1 a string en str con el formato indicado
	ssd1306_display_text(&dev, 1, str, 16, false);	//Agrego str(V1) a OLED

	v2 = 2048.9895;
	ESP_LOGI(pcTaskGetName(NULL), "V2= %0.4f", v2); //V2 a la consola
	memset(str, ' ', L);					//limpio str
	sprintf(str, "V2: %0.4f", v2);	//V2 a string en str con el formato indicado
	ssd1306_display_text(&dev, 3, str, 16, false);	//Agrego str(V2) a OLED

	v3 = -0.6543;
	ESP_LOGI(pcTaskGetName(NULL), "V3= %0.4f", v3); //V3 a la consola
	memset(str, ' ', L);					//limpio str
	sprintf(str, "V3: %0.4f", v3);	//V3 a string en str con el formato indicado
	ssd1306_display_text(&dev, 5, str, 16, false);	//Agrego str(V3) a OLED

	v4 = -2048.9895;
	ESP_LOGI(pcTaskGetName(NULL), "V4= %0.4f", v4); //V4 a la consola
	memset(str, ' ', L);					//limpio str
	sprintf(str, "V4: %0.4f", v4);	//V4 a string en str con el formato indicado
	ssd1306_display_text(&dev, 7, str, 16, false);	//Agrego str(V4) a OLED
	vTaskDelete(NULL);								//finalizo la tarea
}

void app_main(void) {
	//xTaskCreate(&tarea_ssd1306, "tarea_ssd1306", 4096, NULL, 5, NULL);

	uint8_t L = 16;	//Numero maximo de caracteres por fila
	char str[L + 1]; //para guardar el string de cada fila
	float v1, v2, v3, v4;
	SSD1306_t dev;
	i2c_master_init(&dev, CONFIG_SDA_GPIO, CONFIG_SCL_GPIO, CONFIG_RESET_GPIO);
	ssd1306_init(&dev, 128, 64);

	ssd1306_clear_screen(&dev, false);
	ssd1306_contrast(&dev, 0xff);

	ssd1306_display_text(&dev, 0, "  VALOR MEDIDO  ", 16, true); //PONGO EL TITULO

	v1 = 0.1234;
	ESP_LOGI(pcTaskGetName(NULL), "V1= %0.4f", v1); //V1 a la consola
	memset(str, ' ', L);					//limpio str
	//sprintf(str, "               ");
	sprintf(str, "V1: %0.4f", v1);	//V1 a string en str con el formato indicado
	ssd1306_display_text(&dev, 1, str, 16, false);	//Agrego str(V1) a OLED

	v2 = 2048.9895;
	ESP_LOGI(pcTaskGetName(NULL), "V2= %0.4f", v2); //V2 a la consola
	memset(str, ' ', L);					//limpio str
	sprintf(str, "V2: %0.4f", v2);	//V2 a string en str con el formato indicado
	ssd1306_display_text(&dev, 3, str, 16, false);	//Agrego str(V2) a OLED

	v3 = -0.6543;
	ESP_LOGI(pcTaskGetName(NULL), "V3= %0.4f", v3); //V3 a la consola
	memset(str, ' ', L);					//limpio str
	sprintf(str, "V3: %0.4f", v3);	//V3 a string en str con el formato indicado
	ssd1306_display_text(&dev, 5, str, 16, false);	//Agrego str(V3) a OLED

	v4 = -2048.9895;
	ESP_LOGI(pcTaskGetName(NULL), "V4= %0.4f", v4); //V4 a la consola
	memset(str, ' ', L);					//limpio str
	sprintf(str, "V4: %0.4f", v4);	//V4 a string en str con el formato indicado
	ssd1306_display_text(&dev, 7, str, 16, false);	//Agrego str(V4) a OLED

}
