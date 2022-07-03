//0x3c oled
//0x68 mcp3424

#include <driver/i2c.h>
#include <esp_log.h>
#include "sdkconfig.h"
#define RESET_PIN 16//reset_pin=0 si no existe
#define I2C_NUM I2C_NUM_1//Controlador I2C en uso


void buscar() {
	int i;
	esp_err_t espRc;
	printf("     0  1  2  3  4  5  6  7  8  9  a  b  c  d  e  f\n");
	printf("00:         ");
	for (i = 3; i < 0x78; i++) {
		i2c_cmd_handle_t cmd = i2c_cmd_link_create();
		i2c_master_start(cmd);
		i2c_master_write_byte(cmd, (i << 1) | I2C_MASTER_WRITE,
				1 /* expect ack */);
		i2c_master_stop(cmd);

		espRc = i2c_master_cmd_begin(I2C_NUM, cmd, 10 / portTICK_PERIOD_MS);
		if (i % 16 == 0) {
			printf("\n%.2x:", i);
		}
		if (espRc == 0) {
			printf(" %.2x", i);
		} else {
			printf(" --");
		}
		i2c_cmd_link_delete(cmd);
	}
	printf("\n\n");
}

void app_main() {
	//Definimor el puerto I2C como master
	i2c_driver_install(I2C_NUM, I2C_MODE_MASTER, 0, 0, 0);
	//Configuramos I2C
	i2c_config_t conf;
	conf.mode = I2C_MODE_MASTER;
	conf.sda_pullup_en = GPIO_PULLUP_ENABLE;
	conf.scl_pullup_en = GPIO_PULLUP_ENABLE;
	conf.master.clk_speed = 1000000;

	//I2C en los GPIO4 y GPIO15
	conf.sda_io_num = 4;
	conf.scl_io_num = 15;
	i2c_param_config(I2C_NUM, &conf);

	//Es necesario configurar el GPIO16 de reset para poder ver la direccion del OLED
	if (RESET_PIN > 0) {
		gpio_reset_pin(RESET_PIN);
		gpio_set_direction(RESET_PIN, GPIO_MODE_OUTPUT);
		gpio_set_level(RESET_PIN, 0);
		vTaskDelay(50 / portTICK_PERIOD_MS);
		gpio_set_level(RESET_PIN, 1);
	}
	printf("     OLED: SDA=4; SCL=15\n");
	buscar();

	//Cambio I2C a los GPIO21 y GPIO22
	conf.sda_io_num = 21;
	conf.scl_io_num = 22;
	i2c_param_config(I2C_NUM, &conf);

	printf("     I/O: /SDA=21; SCL=22\n");
	buscar();;
}
