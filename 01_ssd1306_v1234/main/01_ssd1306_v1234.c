#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_log.h"

#include "ssd1306.h" //0.96-inch 128*64 dot matrix OLED display
#include "font8x8_basic.h"
#define tag "SSD1306"

void app_main(void) {
	SSD1306_t dev;
	char str[80]; //para guarda la conversion a string de v1,v2,v3,v4
	float v1, v2, v3, v4;
	v1=0.123456;
	v2=-0.654321;
	v3=1234.567891;
	v4=-4321.987654;

	i2c_master_init(&dev, CONFIG_SDA_GPIO, CONFIG_SCL_GPIO, CONFIG_RESET_GPIO);

#if CONFIG_FLIP
	dev._flip = true;
#endif

	ssd1306_init(&dev, 128, 64);
	ssd1306_clear_screen(&dev, false);
	ssd1306_contrast(&dev, 0xff);

	ssd1306_display_text(&dev, 0, "  VALOR MEDIDO  ", 16, true); //PONGO EL TITULO

	ESP_LOGI(pcTaskGetName(NULL), "V1= %0.6f", v1); //V1 a la consola
	sprintf(str, "V1: %0.6f", v1);					//V1 a string en str con el formato indicado
	ssd1306_display_text(&dev, 1, str, 16, false);	//Agrego str(V1) a OLED

	ESP_LOGI(pcTaskGetName(NULL), "V2= %0.6f", v2); //V2 a la consola
	sprintf(str, "V2: %0.6f", v2);					//V2 a string en str con el formato indicado
	ssd1306_display_text(&dev, 3, str, 16, false);	//Agrego str(V2) a OLED

	ESP_LOGI(pcTaskGetName(NULL), "V3= %0.6f", v3); //V3 a la consola
	sprintf(str, "V3: %0.6f", v3);					//V3 a string en str con el formato indicado
	ssd1306_display_text(&dev, 5, str, 16, false);	//Agrego str(V3) a OLED

	ESP_LOGI(pcTaskGetName(NULL), "V4= %0.6f", v4); //V4 a la consola
	sprintf(str, "V4: %0.6f", v4);					//V4 a string en str con el formato indicado
	ssd1306_display_text(&dev, 7, str, 16, false);	//Agrego str(V4) a OLED

}
