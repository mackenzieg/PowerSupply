#ifndef INA219_H_
#define INA219_H_

#include <stdint.h>
#include "../Defines.h"
#include "../twowire/TwoWire.h"

#define CHANNEL_ONE_SHUNT_ADDRESS		0x40
#define CHANNEL_TWO_SHUNT_ADDRESS		0x45

#define CONFIG_REGISTER					0x00
#define CONFIG_RESET					0x8000

#define CONFIG__VOLTAGE_32V				0x2000

#define CONFIG_GAIN_MASK				0x1800
#define CONFIG_GAIN_1					0x0000
#define CONFIG_GAIN_2					0x0800

#define CONFIG_RES_MASK					0x0780
#define CONFIG_RES_11BIT				0x0200
#define CONFIG_RES_12BIT				0x0400

#define CONFIG_SAMPLE_12BIT_1S			0x0018
#define CONFIG_SAMPLE_12BIT_2S			0x0048
#define CONFIG_SAMPLE_12BIT_32S			0x0068
#define CONFIG_SAMPLE_12BIT_64S			0x0070

#define CONFIG_MODE_MASK				0x0007
#define CONFIG_MODE_POWERDOWN			0x0000
#define CONFIG_MODE_SVOLT_TRIGGERED     0x0001
#define CONFIG_MODE_BVOLT_TRIGGERED     0x0002
#define CONFIG_MODE_SBVOLT_TRIGGERED    0x0003
#define CONFIG_MODE_SVOLT_CONTINUOUS    0x0006
#define CONFIG_MODE_BVOLT_CONTINUOUS    0x0007
#define CONFIG_MODE_SBVOLT_CONTINUOUS   0x0008

#define SHUNTVOLTAGE_REGISTER			0x01

#define BUSVOLTAGE_REGISTER				0x02

#define POWER_REGISTER					0x03

#define CURRENT_REGISTER				0x04

#define CALIBRATION_REGISTER			0x05

uint16_t calValue;
uint16_t currentDivider;
uint16_t powerDivider;
uint8_t data[2] = {};

void initINA219(uint8_t address);
void setCalibration(uint8_t address);
float getBusVoltage(uint8_t address);
float getShuntVoltage(uint8_t address);
float getCurrent(uint8_t address);

#endif