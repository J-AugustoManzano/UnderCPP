// c03ex64.cpp

#include <iostream>
#include <print>
#include <concepts>

// Defini��o de Concept que restringe o uso a tipos num�ricos (inteiros e floats)
template <typename T>
concept Numerico = std::is_arithmetic_v<T>;

// Fun��o gen�rica que usa o Concept "Numerico"
template <Numerico T>
T dobro(T valor) {
    return valor * 2;
}

int main(void) {
    // Exemplos v�lidos: inteiros e floats
    std::println("Dobro de 5 ..........: {:>2}", dobro(5));        // Sa�da: Dobro de 5: 10
    std::println("Dobro de 3.14 .......: {:>5.2f}", dobro(3.14));  // Sa�da: Dobro de 3.14: 6.28

    // Exemplo inv�lido: uso de tipo n�o num�rico resulta erro de compila��o
    // std::println"Dobro de uma string ..: {}", dobro("texto"));  // Erro de compila��o

    std::println("");
    std::print("Tecle <Enter> para encerrar... ");
    std::cin.get();

    return 0;
}
