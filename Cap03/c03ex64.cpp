// c03ex64.cpp

#include <iostream>
#include <print>
#include <concepts>

// Definição de Concept que restringe o uso a tipos numéricos (inteiros e floats)
template <typename T>
concept Numerico = std::is_arithmetic_v<T>;

// Função genérica que usa o Concept "Numerico"
template <Numerico T>
T dobro(T valor) {
    return valor * 2;
}

int main(void) {
    // Exemplos válidos: inteiros e floats
    std::println("Dobro de 5 ..........: {:>2}", dobro(5));        // Saída: Dobro de 5: 10
    std::println("Dobro de 3.14 .......: {:>5.2f}", dobro(3.14));  // Saída: Dobro de 3.14: 6.28

    // Exemplo inválido: uso de tipo não numérico resulta erro de compilação
    // std::println"Dobro de uma string ..: {}", dobro("texto"));  // Erro de compilação

    std::println("");
    std::print("Tecle <Enter> para encerrar... ");
    std::cin.get();

    return 0;
}
