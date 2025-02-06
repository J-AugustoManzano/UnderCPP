// c03ex02.cpp

#include <iostream>
#include <print>
#include <vector>
#include <limits>

int main(void) {
    std::vector<int32_t> numeros;
    int32_t valor;

    size_t i {0};
    do {
        std::print("Entre o {:>3}o. elemento: ", i + 1 );

        if (std::cin >> valor) {
            numeros.push_back(valor); // Adiciona o valor ao vetor, expandindo-o
            ++i;
        } else {
            char c;
            std::cin.clear(); // Limpa o estado de erro do cin
            std::cin >> c; // Lê o próximo caractere
            if (c == '.') { break; }
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    } while (true);

    std::println("");
    for (size_t i = 0; i < numeros.size(); ++i) {
        std::println("Elemento {:>3} = {:>8}", i + 1, numeros[i]);
    }

    std::println("");
    std::print("Tecle <Enter> para encerrar... ");
    std::cin.get();
    std::cin.get();

    return 0;
}
