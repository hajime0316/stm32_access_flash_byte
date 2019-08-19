#include "stm32f3_access_flash_byte.hpp"

Stm32f3AccessFlashByte::Stm32f3AccessFlashByte(int index)
{
    index_ = index;
    HAL_FLASHEx_OBGetConfig(&OBInit_);
    OBInit_.OptionType = OPTIONBYTE_DATA | OPTIONBYTE_USER | OPTIONBYTE_DATA;
}

Stm32f3AccessFlashByte::~Stm32f3AccessFlashByte()
{
}
