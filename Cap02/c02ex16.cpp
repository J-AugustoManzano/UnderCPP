// c02ex16.cpp

#include <iostream>
#include <print>

int main(void)
{

    std::println("Esquerda ......: {:*<8}", 10);
    std::println("Direita .......: {:*>8}", 10);
    std::println("Centralizado ..: {:*^8}", 10);

    std::println("");
    std::print("Tecle <Enter> para encerrar... ");
    std::cin.get();

    return 0;
}
