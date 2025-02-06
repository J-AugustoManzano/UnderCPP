// c0Xex08.cpp

#include <iostream>
#include <locale>
#include <iomanip>
#include <sstream>
#include <print>

struct Pontuacao : std::numpunct<char>
{
    // Definir o agrupamento (separador de milhares)
    std::string do_grouping() const override {
        return "\3";  // Usar 3 para agrupar em milhares
    }

    // Definir o separador decimal
    char do_decimal_point() const override {
        return ',';  // Usar vírgula como separador decimal
    }

    // Definir o separador de milhares
    char do_thousands_sep() const override {
        return '.';  // Usar ponto como separador de milhares
    }
};

int main(void) {
    double numero = 1234567.89;

    // Definir a localidade para usar a customização de pontuação
    std::locale loc(std::locale(), new Pontuacao);

    // Usar std::ostringstream para formatar o número com a localidade
    std::ostringstream oss;
    oss.imbue(loc);
    oss << std::fixed << std::setprecision(2) << numero;

    // Exibir o número com o formato desejado usando a biblioteca <print>
    std::println("Numero formatado: {}", oss.str());

    std::println("");
    std::print("Tecle <Enter> para encerrar... ");
    std::cin.get();

    return 0;
}
