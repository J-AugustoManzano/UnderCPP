// c02ex13.cpp

#include <iostream>
#include <print>

int main(void)
{
    int16_t valor = 10;

    std::println("Valor decimal .................: {}", valor);
    std::println("Valor binario .................: {:b}", valor);
    std::println("Valor octal ...................: {:o}", valor);
    std::println("Valor hexadecimal (minusculo) .: {:x}", valor);
    std::println("Valor hexadecimal (maiusculo) .: {:X}", valor);

    std::println("");
    std::print("Tecle <Enter> para encerrar... ");
    std::cin.get();

    return 0;
}
