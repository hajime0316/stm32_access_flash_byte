#ifndef STM32F3_ACCESS_FLASH_BYTE_HPP_
#define STM32F3_ACCESS_FLASH_BYTE_HPP_

#include "stm32f3xx_hal.h"

class Stm32f3AccessFlashByte
{
    private:
        int index_;
        unsigned char data_;
        FLASH_OBProgramInitTypeDef OBInit_;

    public:
        Stm32f3AccessFlashByte(int);
        ~Stm32f3AccessFlashByte();
        unsigned char get();
        void save();

    private:
        int is_index(int);
};

#endif // STM32F3_ACCESS_FLASH_BYTE_HPP_
