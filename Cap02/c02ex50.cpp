// c02ex50.cpp

#include <iostream>
#include <print>
#include <limits>
#include <cctype>

int main(void) {
    int16_t n, r;

    char continuar = 'S';
    do {

        std::print("Entre o valor da tabuada: ");
        std::cin >> n;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::println("");

        for (int16_t i = 1; i <= 10; ++i) {
            r = n * i;
            std::println("{:>2} X {:>2} = {:>3}", n, i, r);
        }

        std::println("");
        std::println("Deseja calcular outra tabuada?");
        std::print("Tecle \"S\" para sim - qualquer outra letra para nao): ");
        std::cin >> continuar;
        continuar = toupper(continuar);  // Converte para maiúscula
        std::println("");
    } while (continuar == 'S');

    std::println("");
    std::print("Tecle <Enter> para encerrar... ");
    std::cin.get();

    return 0;
}
