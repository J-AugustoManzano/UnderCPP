// c06ex01.cpp

#include <iostream>
#include <print>
#include <iomanip>
#include <chrono>

int main(void) {
    // Capturar o horário atual do sistema
    std::chrono::time_point<std::chrono::system_clock>
        agora = std::chrono::system_clock::now();

    // Converter para tempo do sistema
    std::time_t tempo = std::chrono::system_clock::to_time_t(agora);

    // Converter para estrutura tm (localtime)
    std::tm tempoLocal = *std::localtime(&tempo);

    // std::ostringstream e std::put_time para formatar data/hora
    std::ostringstream oss;
    oss << std::put_time(&tempoLocal, "%a %b %d %H:%M:%S %Y");
    std::string tempoFormatado = oss.str();

    // Imprimir o horário formatado
    std::println("{}", tempoFormatado);

    std::println("");
    std::print("Tecle <Enter> para encerrar... ");
    std::cin.get();

    return 0;
}

