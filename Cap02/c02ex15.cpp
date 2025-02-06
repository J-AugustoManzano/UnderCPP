// c02ex15.cpp

#include <iostream>
#include <print>

int main(void)
{

    std::println("Numeros: {}, {} e {}", 1, 3, 2);     // mostra: 1, 3, 2
    std::println("Numeros: {0}, {1} e {2}", 1, 3, 2);  // mostra: 1, 3, 2
    std::println("Numeros: {0}, {2} e {1}", 1, 3, 2);  // mostra: 1, 2, 3
    std::println("Numeros: {2}, {1} e {0}", 1, 3, 2);  // mostra: 2, 3, 1

    std::println("");
    std::print("Tecle <Enter> para encerrar... ");
    std::cin.get();

    return 0;
}
