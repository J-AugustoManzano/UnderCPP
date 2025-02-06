// c08ex04.cpp

#include <iostream>
#include <print>
#include <functional>

// Fun��o que aceita outra fun��o como par�metro
int16_t calc(const int16_t a, const int16_t b,
    std::function<int16_t(const int16_t, const int16_t)> opera) {
    return opera(a, b);
}

int main(void) {
    std::println("Soma .....: {:>2}", calc(5, 3,
        [](const int16_t a, const int16_t b) { return a + b; }));  // Sa�da:  8
    std::println("Produto ..: {:>2}", calc(5, 3,
        [](const int16_t a, const int16_t b) { return a * b; }));  // Sa�da: 15

    std::println("");
    std::print("Tecle <Enter> para encerrar... ");
    std::cin.get();

    return 0;
}
