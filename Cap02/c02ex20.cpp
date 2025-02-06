// c02ex20.cpp

#include <iostream>
#include <print>

int main(void)
{

    std::println("Real {1:8.2f} - Inteiro {0}", 1, 1.5);

    std::println("");
    std::print("Tecle <Enter> para encerrar... ");
    std::cin.get();

    return 0;
}
