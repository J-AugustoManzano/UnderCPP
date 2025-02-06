// c03ex29.cpp

#include <iostream>
#include <print>

int main(void) {
    int16_t idade = 25;
    int16_t* ptrIdade = &idade;

    std::println("Idade    = {} em {:x}", idade, reinterpret_cast<std::uintptr_t>(ptrIdade));
    std::println("ptrIdade = {} em {:x}", *ptrIdade, reinterpret_cast<std::uintptr_t>(&ptrIdade));

    std::println("");
    std::print("Tecle <Enter> para encerrar... ");
    std::cin.get();

    return 0;
}
