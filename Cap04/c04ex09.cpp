// c04ex09.cpp

#include <iostream>
#include <locale>
#include <print>

struct Pontuacao : std::numpunct<char> {
    std::string do_grouping() const override {
        return "\3"; // Agrupa de três em três dígitos
    }

    char do_decimal_point() const override {
        return ','; // Usa a vírgula como separador decimal
    }

    char do_thousands_sep() const override {
        return '.'; // Usa o ponto como separador de milhares
    }
};

int main(void) {
    double valorFinanceiro = 9999999999999.99;  // 9.999.999.999.999,99

    // Aplica a formatação global
    std::locale::global(std::locale(std::locale(), new Pontuacao));

    // Imprime o valor formatado
    std::print("Valor R$ {:L}\n", valorFinanceiro);

    std::println("");
    std::print("Tecle <Enter> para encerrar... ");
    std::cin.get();

    return 0;
}
