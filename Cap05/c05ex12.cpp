// c05ex12.cpp

#include <iostream>
#include <print>

int main(void) {
    int16_t x = 5;
    float y = 2.5, resultado;

    // O compilador converte implicitamente o int 'x' para float para a opera��o
    resultado = x + y;

    std::println("Resultado: {}", resultado);  // Sa�da: 7.5

    std::println("");
    std::print("Tecle <Enter> para encerrar... ");
    std::cin.get();

    return 0;
}
