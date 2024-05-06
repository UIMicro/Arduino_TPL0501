#include "TPL0501.h"

TPL0501* tpl = nullptr;

void setup() {
  // put your setup code here, to run once:
    tpl = new TPL0501(A5, A1, A0);
    Serial.begin(230400);
}

uint8_t cnt = 0;

void loop() {
  // put your main code here, to run repeatedly:
    cnt += 4;
    Serial.println(cnt);
    Serial.println(cnt * 3.3 / 255.0 );
    tpl->setResistor(cnt);
    while (!Serial.available());
    Serial.read();
}
