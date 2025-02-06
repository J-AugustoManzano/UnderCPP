// c03ex15.cpp

#include <iostream>
#include <string>
#include <vector>
#include <print>

int main(void) {
    std::vector<int64_t> numeros;
    std::string entrada;

    std::println("Entre valores inteiros (use '.' para terminar):");
    std::println("");

    do {
        bool ehNumero = true;
        std::getline(std::cin, entrada);

        // Verifica se a entrada é apenas dígitos
        size_t i = 0;
        while (i < entrada.length()) {
            if (not std::isdigit(entrada[i]) and entrada[i] != '-') {
                ehNumero = false;
                break;
            }
            ++i;
        }

        if (entrada == ".") {break;}

        if (ehNumero and not entrada.empty()) {
            numeros.push_back(std::stoll(entrada));
        } else {
            std::println("Entrada invalida, tente novamente.");
        }
    } while (true); // Continua até que o caractere "." seja digitado

    int64_t soma = 0;
    for (const int64_t &valor : numeros) {
        soma += valor;
    }

    std::println("");
    std::println("Somatorio = {}", soma);

    std::println("");
    std::print("Tecle <Enter> para encerrar... ");
    std::cin.get();

    return 0;
}
