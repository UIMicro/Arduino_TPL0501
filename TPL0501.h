#ifndef _TPL0501_H
#define _TPL0501_H

#include <SPI.h>

class TPL0501 {
private:
    static const int spiClockSpeed = 100000; // should be less than 25M
    SPIClass* tpl_spi = nullptr;
public:
    TPL0501(int8_t SCLK, int8_t DIN, int8_t CS);
    void setResistor(uint8_t value);
};

#endif