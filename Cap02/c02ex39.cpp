// c02ex39.cpp

#include <iostream>
#include <print>
#include <limits>
#include <cctype>

int main(void) {
    int16_t n, i, r;

    char continuar = 'S';  // cria e inicializa com 'S' para entrar no laço
    while (not (continuar != 'S')) {
        std::print("Entre o valor da tabuada: ");
        std::cin >> n;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::println("");

        i = 1;
        while (not (i > 10)) {
            r = n * i;
            std::println("{:>2} X {:>2} = {:>3}", n, i, r);
            ++i;
        }

        std::println("");

        // Solicita ao usuário se quer continuar
        std::println("Deseja calcular outra tabuada?");
        std::print("Tecle \"S\" para sim - qualquer outra letra para nao): ");
        std::cin >> continuar;
        continuar = toupper(continuar);  // Converte para maiúscula
        std::println("");
    }

    std::print("Tecle <Enter> para encerrar... ");
    std::cin.ignore();
    std::cin.get();

    return 0;
}
