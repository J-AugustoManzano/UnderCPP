// c06ex04.cpp

#include <iostream>
#include <chrono>
#include <print>
#include <string>
#include <chrono>

bool dataValida(uint16_t dia, uint16_t mes, uint16_t ano) {
    if (ano < 1970 or ano > 9999 or mes < 1 or mes > 12 or dia < 1) {
        return false;
    }

    constexpr int16_t diasPorMes[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

    bool ehBissexto = (ano % 4 == 0 and ano % 100 != 0) || (ano % 400 == 0);
    uint16_t diasNoMes = diasPorMes[mes - 1] + (mes == 2 and ehBissexto ? 1 : 0);

    return dia <= diasNoMes;
}

bool validaComChrono(uint16_t dia, uint16_t mes, uint16_t ano) {
    try {
        std::chrono::year_month_day
            amd{std::chrono::year{ano}, std::chrono::month{mes}, std::chrono::day{dia}};
        return amd.ok();
    } catch (...) {
        return false;
    }
}

int main(void) {
    std::string entrada;
    uint16_t dia, mes, ano;

    std::print("Entre data no formato DD/MM/AAAA: ");
    std::getline(std::cin, entrada);
    std::println("");

    std::istringstream iss(entrada);
    char separador1, separador2;
    if (iss >> dia >> separador1 >> mes >> separador2 >> ano and
        separador1 == '/' and separador2 == '/' and dataValida(dia, mes, ano) and
        validaComChrono(dia, mes, ano)) {
        std::println("Data valida: {:02}/{:02}/{:04}", dia, mes, ano);
    } else {
        std::println("Erro: data invalida.");
        std::println("");
        std::println("Entre a data no formato DD/MM/AAAA, com:");
        std::println("");
        std::println("- dia: entre 1 e 31, considerando 30 ou 29 dias dependendo do mes;");
        std::println("- mes: entre 1 e 12;");
        std::println("- ano: entre 1970 e 9999;");
    }

    std::println("");
    std::print("Tecle <Enter> para encerrar... ");
    std::cin.get();

    return 0;
}

