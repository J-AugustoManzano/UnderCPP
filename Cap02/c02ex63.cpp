// c02ex63.cpp

#include <iostream>
#include <print>
#include <cctype>  // Para verificar se h� n�meros na entrada

int main(void) {
    int16_t i;
    std::string entrada;
    bool ehTexto;

    do {
        std::print("Entre com um texto (sem numeros): ");
        std::getline(std::cin, entrada); // Captura a linha inteira de texto

        ehTexto = true; // Presume que a entrada � v�lida

        // Verifica se a entrada cont�m apenas letras
        i = 0;
        while (i < entrada.length()) {
            if (std::isdigit(entrada[i])) { // Verifica se h� d�gitos
                ehTexto = false;
                break;
            }
            ++i;
        }

        if (not ehTexto) {
            std::println("Entrada invalida. Por favor, entre apenas texto (sem numeros).");
            std::println("");
        }

    } while (not ehTexto); // Continua o la�o at� a entrada ser v�lida

    std::println("");
    std::println("Texto informado = {}", entrada);

    std::println("");
    std::print("Tecle <Enter> para encerrar... ");
    std::cin.get();

    return 0;
}
