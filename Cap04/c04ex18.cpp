// c04ex18.cpp

#include <iostream>
#include <print>
#include <cstdint>
#include <limits>  // Para std::numeric_limits
#include <sstream> // Para std::stringstream
#include "calc.hpp"

// Fun��o para validar se a entrada � um n�mero inteiro v�lido
bool validarInteiro(const std::string& entrada, int16_t& valor) {
    std::stringstream ss(entrada);
    int32_t numero;

    // Tenta converter a string para um n�mero inteiro
    ss >> numero;

    // Verifica se a convers�o foi bem-sucedida e se n�o sobrou nenhum
    // caractere na string
    if (ss.fail() or not ss.eof()) {
        return false;
    }

    // Verifica se o n�mero est� dentro do intervalo de int16_t
    if (numero >= std::numeric_limits<int16_t>::min()
        and numero <= std::numeric_limits<int16_t>::max()) {
        valor = static_cast<int16_t>(numero);
        return true;
    }

    return false;
}

int main(void) {
    std::string entrada;
    int16_t valor;
    bool entradaValida;

    do {
        std::print("Entre um numero inteiro: ");
        std::getline(std::cin, entrada);

        entradaValida = validarInteiro(entrada, valor);

        if (not entradaValida) {
            std::println("Entrada invalida. Informe um numero inteiro.");
        }
    } while (not entradaValida);

    // Exibe o fatorial e o somat�rio usando a biblioteca calc.hpp
    std::println("Fatorial de ...: {} = {}", valor, fatorial(valor));
    std::println("Somatorio de ..: {} = {}", valor, somatorio(valor));

    std::println("");
    std::print("Tecle <Enter> para encerrar... ");
    std::cin.get();

    return 0;
}
