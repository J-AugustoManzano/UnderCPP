// c03ex28.cpp

#include <iostream>
#include <print>

int main(void) {
    int16_t idade = 25;
    int16_t* ptrIdade = nullptr;

    ptrIdade = &idade;

    std::print("Idade de {} esta no endereco de memoria ", idade);
    std::println("{:x}.", reinterpret_cast<std::uintptr_t>(ptrIdade));

    std::println("");
    std::print("Tecle <Enter> para encerrar... ");
    std::cin.get();

    return 0;
}
