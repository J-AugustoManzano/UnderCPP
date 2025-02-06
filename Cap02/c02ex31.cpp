// c02ex31.cpp

#include <iostream>
#include <print>
#include <limits>

int main(void) {
    float a, b, r;
    int16_t opcao;

    std::print("Entre o valor <A>: ");
    std::cin >> a;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::print("Entre o valor <B>: ");
    std::cin >> b;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::println("");
    std::println("[1] - Adicao");
    std::println("[2] - Subtracao");
    std::println("[3] - Multiplicacao");
    std::println("[4] - Divisao");
    std::println("");

    std::print("Escolha uma opcao: ");
    std::cin >> opcao;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    if (opcao == 1) {
        r = a + b;
    }
    if (opcao == 2) {
        r = a - b;
    }
    if (opcao == 3) {
        r = a * b;
    }
    if (opcao == 4) {
        if (b == 0) {
          r = 0;
        } else {
          r = a / b;
        }
    }
    if (opcao >= 1 and opcao <= 4) {
        std::println("\nResultado = {:.2f}", r);
    } else {
        std::println("\nOpcao invalida.");
    }

    std::println("");
    std::print("Tecle <Enter> para encerrar... ");
    std::cin.get();

    return 0;
}
