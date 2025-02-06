// c03ex34.cpp

#include <iostream>
#include <print>
#include <limits>

int main(void) {
    int16_t idade = 25;
    int16_t* pIdade1 = nullptr;
    int16_t* pIdade2 = nullptr;

    pIdade1 = &idade;
    pIdade2 = pIdade1;

    std::println("Variavel \"idade\" ....: {}", idade);
    std::println("Ponteiro \"pIdade1\" ..: {:p}", static_cast<void*>(pIdade1));
    std::println("Ponteiro \"pIdade2\" ..: {:p}", static_cast<void*>(pIdade2));

    std::println("");
    std::print("Tecle <Enter> para encerrar... ");
    std::cin.get();

    return 0;
}
