// c04ex18.cpp

#include <iostream>
#include <print>
#include <cstdint>
#include <limits>  // Para std::numeric_limits
#include <sstream> // Para std::stringstream
#include "calc.hpp"

// Função para validar se a entrada é um número inteiro válido
bool validarInteiro(const std::string& entrada, int16_t& valor) {
    std::stringstream ss(entrada);
    int32_t numero;

    // Tenta converter a string para um número inteiro
    ss >> numero;

    // Verifica se a conversão foi bem-sucedida e se não sobrou nenhum
    // caractere na string
    if (ss.fail() or not ss.eof()) {
        return false;
    }

    // Verifica se o número está dentro do intervalo de int16_t
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

    // Exibe o fatorial e o somatório usando a biblioteca calc.hpp
    std::println("Fatorial de ...: {} = {}", valor, fatorial(valor));
    std::println("Somatorio de ..: {} = {}", valor, somatorio(valor));

    std::println("");
    std::print("Tecle <Enter> para encerrar... ");
    std::cin.get();

    return 0;
}
