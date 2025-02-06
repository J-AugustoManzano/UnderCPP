// c03ex39.cpp

#include <iostream>
#include <print>

int main(void) {
    int16_t a = 1;
    float b = 2.5f;
    void *pGenerico = nullptr;

    pGenerico = &a; // Ponteiro aponta para variável "a" do tipo int16_t
    std::println("Valor inteiro ...: {}", *(static_cast<int16_t*>(pGenerico)));

    pGenerico = &b; // Ponteiro aponta para variável "b" do tipo float
    std::println("Valor real ......: {}", *(static_cast<float*>(pGenerico)));

    std::println("");
    std::print("Tecle <Enter> para encerrar... ");
    std::cin.get();

    return 0;
}
