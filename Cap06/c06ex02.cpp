// c06ex02.cpp

#include <iostream>
#include <print>
#include <iomanip>
#include <chrono>

int main(void) {
    // Captura o horário atual do sistema
    std::chrono::time_point<std::chrono::system_clock> agora = std::chrono::system_clock::now();

    // Converte para tempo no formato `time_t`
    std::time_t tempo = std::chrono::system_clock::to_time_t(agora);

    // Converte para formato de tempo local
    std::tm momento = *std::localtime(&tempo);

    // Exibição dos dados formatados usando `std::print` e preenchimento moderno
    std::println("Dia .......: {:02}", momento.tm_mday);
    std::println("Mes .......: {:02}", momento.tm_mon + 1);
    std::println("Ano .......: {:04}", momento.tm_year + 1900);
    std::println("");
    std::println("Hora ......: {:02}", momento.tm_hour);
    std::println("Minuto ....: {:02}", momento.tm_min);
    std::println("Segundo ...: {:02}", momento.tm_sec);

    std::println("");
    std::print("Tecle <Enter> para encerrar... ");
    std::cin.get();

    return 0;
}

