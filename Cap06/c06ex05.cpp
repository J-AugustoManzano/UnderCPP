// c06ex05.cpp

#include <iostream>
#include <chrono>
#include <print>
#include <iomanip>  // para: std::put_time
#include <sstream>  // para: std::ostringstream / .str()

int main(void) {
    // Tempo local no Brasil
    std::chrono::system_clock::time_point agora = std::chrono::system_clock::now();
    std::time_t tempoLocal = std::chrono::system_clock::to_time_t(agora);
    std::tm tm_local = *std::localtime(&tempoLocal);

    // Tempo em Nova York (Eastern Time)
    std::chrono::system_clock::time_point agoraNY = agora + std::chrono::hours(-5);
    std::time_t tempoNY = std::chrono::system_clock::to_time_t(agoraNY);
    std::tm tm_NY = *std::localtime(&tempoNY);

    // Horário UTC
    std::tm tm_utc = *std::gmtime(&tempoLocal);

    // Mostra a hora local
    std::ostringstream oss_local;
    oss_local << std::put_time(&tm_local, "%d/%m/%Y - %H:%M:%S");
    std::print("Hora local (Brasil) .: {}\n", oss_local.str());

    // Mostra a hora UTC
    std::ostringstream oss_utc;
    oss_utc << std::put_time(&tm_utc, "%d/%m/%Y - %H:%M:%S");
    std::print("Hora UTC ............: {}\n", oss_utc.str());

    // Mostra a hora em Nova York
    std::ostringstream oss_nova_york;
    oss_nova_york << std::put_time(&tm_NY, "%d/%m/%Y - %H:%M:%S");
    std::print("Hora em Nova York ...: {}\n", oss_nova_york.str());

    std::println("");
    std::print("Tecle <Enter> para encerrar... ");
    std::cin.get();

    return 0;
}

