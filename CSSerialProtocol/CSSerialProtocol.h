#pragma once
#include <Arduino.h>

void initSerial(short header, long baudRate = 115200);
int32_t runSerial();
void sendData();
byte* getDataBuffer();
byte* getChecksumArray();
byte* getMsgLengthArray();
uint16_t* getChecksum();
uint16_t* getMsgLength();
template<typename T>
void addData(T input) {
	byte* inputPtr = (byte*) &input;
	for (int i = 0; i < sizeof(input); i++) {
		getDataBuffer()[(*getMsgLength()) + i] = *(inputPtr + i);
		(*getChecksum()) += *(inputPtr + i);
	}
	(*getMsgLength()) += sizeof(input);
}