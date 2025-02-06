// main.cpp

#include <iostream>
#include <print>

extern int var1;
extern float var2;

int main(void) {
    std::println("Variavel 1: {}", var1);
    std::println("Variavel 2: {:.2f}", var2);

    std::println("");
    std::print("Tecle <Enter> para encerrar... ");
    std::cin.get();

    return 0;
}
