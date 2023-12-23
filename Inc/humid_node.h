// Created by RudyPrzyjaciel
//

#ifndef MOISTURE_SENSOR_NODE_HUMID_NODE_H
#define MOISTURE_SENSOR_NODE_HUMID_NODE_H

#include "main.h"

extern void logMessage(char* message);

typedef struct HumidNode{
    // Hardware settings:
    GPIO_TypeDef*           ledPort;
    uint16_t                ledPin;
    GPIO_TypeDef*           moistureSensorPort;
    uint16_t                moistureSensorPin;
    UART_HandleTypeDef*     uart;
    ADC_HandleTypeDef*      adc;

    // Node settings:
    uint32_t                previousTick;
    uint32_t                moistureData;
    char                    messageBuffer[80];
} HumidNode;

HumidNode newHumidNode(void);
void HumidNode_toggleLed(HumidNode* _HumidNode);
void HumidNode_readMoistureSensor(HumidNode* _HumidNode);
void HumidNode_mainLoop(HumidNode* _HumidNode);

#endif//MOISTURE_SENSOR_NODE_HUMID_NODE_H
