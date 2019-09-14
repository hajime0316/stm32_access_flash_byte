#include "cppmain.hpp"

// include for CubeMX
#include "main.h"
#include "tim.h"
#include "gpio.h"

static uint8_t sw_sum;
static int led_flag = 0;

void setup() {
    HAL_TIM_Base_Start_IT(&htim6);
    sw_sum = HAL_FLASHEx_OBGetUserData(OB_DATA_ADDRESS_DATA0);
}

void loop() {
    if(HAL_GPIO_ReadPin(SW_GPIO_Port, SW_Pin) == GPIO_PIN_RESET && led_flag == 0) {
        led_flag = 1;
        HAL_GPIO_WritePin(LED_G_GPIO_Port, LED_G_Pin, GPIO_PIN_SET);

        // sw_sumをインクリメント
        sw_sum++;

        // eepromにsw_sumを記録
        uint32_t address;
        uint8_t data;
        FLASH_OBProgramInitTypeDef OBInit;

        address = OB_DATA_ADDRESS_DATA0;
        data = sw_sum;

        HAL_FLASHEx_OBGetConfig(&OBInit);
        OBInit.OptionType = OPTIONBYTE_DATA | OPTIONBYTE_USER | OPTIONBYTE_DATA;
        OBInit.DATAAddress = address;
        OBInit.DATAData = data;
        
        HAL_FLASH_Unlock();
        HAL_FLASH_OB_Unlock();
        HAL_FLASHEx_OBErase();    // これがないとProgram出来ない．
        HAL_FLASHEx_OBProgram(&OBInit);
        HAL_FLASH_OB_Lock();
        HAL_FLASH_Lock();
    }
    else if (HAL_GPIO_ReadPin(SW_GPIO_Port, SW_Pin) == GPIO_PIN_RESET && led_flag == 1) {
        HAL_GPIO_WritePin(LED_G_GPIO_Port, LED_G_Pin, GPIO_PIN_SET);
    }
    else if(HAL_GPIO_ReadPin(SW_GPIO_Port, SW_Pin) == GPIO_PIN_SET && led_flag == 1) {
        led_flag = 0;
        HAL_GPIO_WritePin(LED_G_GPIO_Port, LED_G_Pin, GPIO_PIN_RESET);
    }
}
