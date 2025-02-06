// c08ex02.cpp

#include <iostream>
#include <print>

// Fun��o de exemplo
int16_t multiplicar(const int16_t a, const int16_t b) {
    return a * b;
}

int main(void) {
    // Atribuindo a fun��o a um ponteiro de fun��o
    int16_t (*operacao)(int16_t, int16_t) = multiplicar;

    // Usando a vari�vel para chamar a fun��o
    std::println("Resultado = {}", operacao(3, 4));  // Resultado = 12

    std::println("");
    std::print("Tecle <Enter> para encerrar... ");
    std::cin.get();

    return 0;
}

