// c06ex03.cpp

#include <iostream>
#include <chrono>
#include <print>
#include <limits>

int main(void) {
    // Definir uma estrutura tm para armazenar os dados da data e hora
    std::tm momento = {};

    // Captura de data e hora do usuário
    std::print("Entre o Dia de uma data ..: ");
    std::cin >> momento.tm_mday;

    std::print("Entre o Mes de uma data ..: ");
    std::cin >> momento.tm_mon;
    momento.tm_mon--;  // Ajuste porque tm_mon começa de 0 (Janeiro)

    std::print("Entre o Ano de uma data ..: ");
    std::cin >> momento.tm_year;
    momento.tm_year -= 1900;  // Ajuste para o ano correto

    std::print("\nEntre a Hora .............: ");
    std::cin >> momento.tm_hour;

    std::print("Entre o Minuto ...........: ");
    std::cin >> momento.tm_min;

    std::print("Entre o Segundo ..........: ");
    std::cin >> momento.tm_sec;

    // Limpar buffer de teclado
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::print("\n{:02}/{:02}/{:04} | {:02}:{:02}:{:02}\n",
                momento.tm_mday,
                momento.tm_mon + 1,
                momento.tm_year + 1900,
                momento.tm_hour,
                momento.tm_min,
                momento.tm_sec);

    std::println("");
    std::print("Tecle <Enter> para encerrar... ");
    std::cin.get();

    return 0;
}

