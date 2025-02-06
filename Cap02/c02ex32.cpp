// c02ex32.cpp

#include <iostream>
#include <print>
#include <limits>

int main(void) {
    int16_t mes;

    std::print("Entre um numero equivalente a um MES: ");
    std::cin >> mes;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::println("");

    switch (mes) {
        case 1:
            std::println("Janeiro");
            break;
        case 2:
            std::println("Fevereiro");
            break;
        case 3:
            std::println("Marco");
            break;
        case 4:
            std::println("Abril");
            break;
        case 5:
            std::println("Maio");
            break;
        case 6:
            std::println("Junho");
            break;
        case 7:
            std::println("Julho");
            break;
        case 8:
            std::println("Agosto");
            break;
        case 9:
            std::println("Setembro");
            break;
        case 10:
            std::println("Outubro");
            break;
        case 11:
            std::println("Novembro");
            break;
        case 12:
            std::println("Dezembro");
            break;
        default:
            std::println("Mes invalido");
            break;
    }

    std::println("");
    std::print("Tecle <Enter> para encerrar... ");
    std::cin.get();

    return 0;
}
