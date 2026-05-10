

How to build PlatformIO based project
=====================================

1. [Install PlatformIO Core](https://docs.platformio.org/page/core.html)
2. Download [development platform with examples](https://github.com/platformio/platform-freescalekinetis/archive/develop.zip)
3. Extract ZIP archive
4. Run these commands:

```shell
# Change directory to example
$ cd platform-freescalekinetis/examples/zephyr-blink

# Build project
$ pio run

# Upload firmware
$ pio run --target upload

# Build specific environment
$ pio run -e frdm_k64f

# Upload firmware for the specific environment
$ pio run -e frdm_k64f --target upload

# Clean build files
$ pio run --target clean
```



https://github.com/user-attachments/assets/7079f76a-5119-4630-93d9-3d7c861b70a0

Para fazer com que a entrada digital funcionasse utilizei o zehpyy 4.2, como é exigido no notion. Para que funcionasse, tive que criar um overlay para o código, assim pude configurar a porta de saída do meu microcontrolador.



