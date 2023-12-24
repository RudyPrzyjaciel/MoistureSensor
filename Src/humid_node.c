// Created by RudyPrzyjaciel
//

#include "humid_node.h"
#include <stdio.h>
HumidNode newHumidNode() {
    HumidNode new_HumidNode;

    // Hardware settings:
    new_HumidNode.ledPort = 0;
    new_HumidNode.ledPin = 0;
    new_HumidNode.moistureSensorPort = 0;
    new_HumidNode.moistureSensorPin = 0;
    new_HumidNode.uart = 0;

    // Node settings:
    new_HumidNode.previousTick = 0;
    new_HumidNode.moistureData = 0;
}

void HumidNode_readMoistureSensor(HumidNode* _HumidNode) {
    logMessage("readMoistureSensor");
    HAL_ADC_Start(_HumidNode->adc);
    HAL_ADC_PollForConversion(_HumidNode->adc, HAL_MAX_DELAY);
    _HumidNode->moistureData = HAL_ADC_GetValue(_HumidNode->adc);
    HAL_ADC_Stop(_HumidNode->adc);

    sprintf(_HumidNode->messageBuffer, "Moisture Analog Value: %d", _HumidNode->moistureData);
    logMessage(_HumidNode->messageBuffer);
}
void HumidNode_mainLoop(HumidNode* _HumidNode) {
    logMessage("main loop");
    uint32_t tick = HAL_GetTick();
    if (tick - _HumidNode->previousTick > 1500) {
        logMessage("few ticks has passed...");
        _HumidNode->previousTick = tick;
        HumidNode_toggleLed(_HumidNode);
    }
    HumidNode_readMoistureSensor(_HumidNode);
}

void HumidNode_toggleLed(HumidNode* _HumidNode) {
    logMessage("Toggle LED");
    HAL_GPIO_TogglePin(_HumidNode->ledPort, _HumidNode->ledPin);
}