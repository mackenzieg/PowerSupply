#ifndef TWOWIRE_H_
#define TWOWIRE_H_

#include "../Defines.h"

void initTwoWire(void);
bool startTwoWire(uint8_t address);
bool writeTwoWire(uint8_t data);
uint8_t readACK(void);
uint8_t readNACK(void);
bool transmitTwoWire(uint8_t address, uint8_t* data, uint16_t length);
bool receiveTwoWire(uint8_t address, uint8_t* data, uint16_t length);
bool writeRegisterTwoWire(uint8_t devaddr, uint8_t regaddr, uint8_t* data, uint16_t length);
bool readRegisterTwoWire(uint8_t devaddr, uint8_t regaddr, uint8_t* data, uint16_t length);
void stopTwoWire(void);

#endif