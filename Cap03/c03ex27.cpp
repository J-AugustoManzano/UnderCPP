// c03ex27.cpp

#include <iostream>
#include <array>
#include <print>

int main(void) {
    // Declara o array sem inicializ�-lo com valores espec�ficos
    std::array<int, 5> numeros;

    // Exibe o conte�do inicial do array (valores indeterminados)
    std::println("Conteudo inicial do arranjo:");
    std::println("");
    for (size_t i = 0; i < numeros.size(); ++i) {
        std::println("Elemento {}: {:>3}", i, numeros[i]);
    }

    // Usa o m�todo fill para preencher todos os elementos com 0
    numeros.fill(0);

    // Exibe o conte�do do array ap�s o uso de fill
    std::println("");
    std::println("Conteudo do arranjo apos fill:");
    std::println("");
    for (size_t i = 0; i < numeros.size(); ++i) {
        std::println("Elemento {}: {:>3}", i, numeros[i]);
    }

    std::println("");
    std::print("Tecle <Enter> para encerrar... ");
    std::cin.get();

    return 0;
}
