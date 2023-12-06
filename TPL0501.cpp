#include "TPL0501.h"

#if CONFIG_IDF_TARGET_ESP32S2 || CONFIG_IDF_TARGET_ESP32S3
#define VSPI FSPI
#endif

TPL0501::TPL0501(int8_t SCLK, int8_t DIN, int8_t CS) {
    tpl_spi = new SPIClass(VSPI);
    tpl_spi->begin(SCLK, -1, DIN, CS);
    pinMode(tpl_spi->pinSS(), OUTPUT);
}

void TPL0501::setResistor(uint8_t value) {
    tpl_spi->beginTransaction(SPISettings(spiClockSpeed, MSBFIRST, SPI_MODE3));
    digitalWrite(tpl_spi->pinSS(), LOW); //pull SS slow to prep other end for transfer
    tpl_spi->transfer(value);
    digitalWrite(tpl_spi->pinSS(), HIGH); //pull ss high to signify end of data transfer
    tpl_spi->endTransaction();
}