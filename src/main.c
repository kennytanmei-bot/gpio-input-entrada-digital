#include <zephyr/kernel.h>
#include <zephyr/device.h>
#include <zephyr/drivers/gpio.h>

/* Pegando a porta E pelo Node Label */
#define GPIOE_NODE DT_NODELABEL(gpioe)
#define INPUT_PIN 20 

int main(void) /* Mudado de void para int */
{
    const struct device *input_dev = DEVICE_DT_GET(GPIOE_NODE);
    int ret, val;

    if (!device_is_ready(input_dev)) {
        printk("Erro: Dispositivo GPIOE nao esta pronto!\n");
        return -1; /* Retorna erro se falhar */
    }

    ret = gpio_pin_configure(input_dev, INPUT_PIN, GPIO_INPUT);
    if (ret != 0) {
        printk("Erro ao configurar pino PTE%d\n", INPUT_PIN);
        return -1;
    }

    printk("Iniciando leitura do pino PTE%d...\n", INPUT_PIN);

    while (1) {
        val = gpio_pin_get(input_dev, INPUT_PIN);
        printk("Valor do PTE%d: %d\n", INPUT_PIN, val);
        k_msleep(100);
    }

    return 0; /* Boas práticas do C */
}