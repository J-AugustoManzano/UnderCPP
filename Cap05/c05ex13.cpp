// c05ex13.cpp

#include <iostream>
#include <print>

int main(void) {
    double pi = 3.14159;
    int16_t x = (int16_t)pi;  // Conversão explícita de double para int16_t

    std::println("Valor de x: {}", x);  // Saída: 3

    std::println("");
    std::print("Tecle <Enter> para encerrar... ");
    std::cin.get();

    return 0;
}
