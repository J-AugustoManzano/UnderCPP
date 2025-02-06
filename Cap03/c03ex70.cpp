// c03ex70.cpp

#include <iostream>
#include <print>
#include <limits>

enum class Meses
{
    janeiro = 1,
    fevereiro,
    marco,
    abril,
    maio,
    junho,
    julho,
    agosto,
    setembro,
    outubro,
    novembro,
    dezembro
};

const char* extenso[] = {
    "janeiro",
    "fevereiro",
    "marco",
    "abril",
    "maio",
    "junho",
    "julho",
    "agosto",
    "setembro",
    "outubro",
    "novembro",
    "dezembro"
};

int main(void)
{
    uint16_t entrada;
    Meses mes;

    std::print("Entre o mes desejado (de 1 ate 12): ");
    std::cin >> entrada;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    mes = static_cast<Meses>(entrada);

    std::println("");
    std::print("Foi informado mes {} -> ", static_cast<int>(mes));
    std::println("que equivale a {}", extenso[static_cast<int>(mes) - 1]);

    std::println("");
    std::print("Tecle <Enter> para encerrar... ");
    std::cin.get();

    return 0;
}
