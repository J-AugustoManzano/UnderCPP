// c02ex17.cpp

#include <iostream>
#include <print>

int main(void)
{

    std::println("Zeros a esquerda ..: {:08}, {:08}", 10, -.2);
    std::println("Espacos em branco .: {:8d}", 10);
    std::println("Sem espacos .......: {:d}", 10);

    std::println("");
    std::print("Tecle <Enter> para encerrar... ");
    std::cin.get();

    return 0;
}
