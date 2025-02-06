// c02ex63.cpp

#include <iostream>
#include <print>
#include <cctype>  // Para verificar se há números na entrada

int main(void) {
    int16_t i;
    std::string entrada;
    bool ehTexto;

    do {
        std::print("Entre com um texto (sem numeros): ");
        std::getline(std::cin, entrada); // Captura a linha inteira de texto

        ehTexto = true; // Presume que a entrada é válida

        // Verifica se a entrada contém apenas letras
        i = 0;
        while (i < entrada.length()) {
            if (std::isdigit(entrada[i])) { // Verifica se há dígitos
                ehTexto = false;
                break;
            }
            ++i;
        }

        if (not ehTexto) {
            std::println("Entrada invalida. Por favor, entre apenas texto (sem numeros).");
            std::println("");
        }

    } while (not ehTexto); // Continua o laço até a entrada ser válida

    std::println("");
    std::println("Texto informado = {}", entrada);

    std::println("");
    std::print("Tecle <Enter> para encerrar... ");
    std::cin.get();

    return 0;
}
