// Created by RudyPrzyjaciel
//

#ifndef MOISTURE_SENSOR_NODE_HUMID_NODE_H
#define MOISTURE_SENSOR_NODE_HUMID_NODE_H

#include "main.h"
#include "LoRa.h"

#define BUFFER_SIZE 120

extern void logMessage(char* message);

typedef struct HumidNode{
    // Hardware settings:
    UART_HandleTypeDef*     uart;
    ADC_HandleTypeDef*      adc;
    SPI_HandleTypeDef*      spi;

    // Node settings:
    uint32_t                previousTick;
    uint32_t                moistureData;
    char                    messageBuffer[BUFFER_SIZE];
    LoRa                    loraModule;

} HumidNode;

HumidNode newHumidNode(void);
void HumidNode_initLoRaModule(HumidNode* _HumidNode);
void HumidNode_readMoistureSensor(HumidNode* _HumidNode);
void HumidNode_mainLoop(HumidNode* _HumidNode);

#endif//MOISTURE_SENSOR_NODE_HUMID_NODE_H
