#ifndef STM32F3_ACCESS_FLASH_BYTE_HPP_
#define STM32F3_ACCESS_FLASH_BYTE_HPP_

class Stm32f3AccessFlashByte
{
    private:
        int index;
        unsigned char data;
        int is_appropriate_index(int index);

    public:
        Stm32f3AccessFlashByte(int index);
        ~Stm32f3AccessFlashByte();
        unsigned char get();
        void save();
};

Stm32f3AccessFlashByte::Stm32f3AccessFlashByte(int index)
{
}

Stm32f3AccessFlashByte::~Stm32f3AccessFlashByte()
{
}


#endif // STM32F3_ACCESS_FLASH_BYTE_HPP_