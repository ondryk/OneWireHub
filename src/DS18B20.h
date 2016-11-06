// 0x28  Digital Thermometer
// Works - 100%

#ifndef ONEWIRE_DS18B20_H
#define ONEWIRE_DS18B20_H

#include "OneWireItem.h"

class DS18B20 : public OneWireItem
{
private:

    uint8_t scratchpad[9];

    void setTemperatureRaw(const int16_t value_raw);
    void updateCRC(void);

    bool ds18s20_mode;

public:

    static constexpr uint8_t family_code = 0x28; // is compatible to ds1822 (0x22) and ds18S20 (0x10)

    DS18B20(uint8_t ID1, uint8_t ID2, uint8_t ID3, uint8_t ID4, uint8_t ID5, uint8_t ID6, uint8_t ID7);

    void duty(OneWireHub * const hub);

    void setTemperature(const float value_degC);
    void setTemperature(const int8_t value_degC);
    int  getTemperature(void) const;

};

#endif
