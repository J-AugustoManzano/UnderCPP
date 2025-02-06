// c06ex09.cpp

#include <iostream>
#include <sstream>
#include <limits>
#include <print>
#include "time.h"

int main(void) {
    std::string entra_hora1, entra_hora2;
    char delimitador;
    uint16_t hora1, minuto1, segundo1;
    uint16_t hora2, minuto2, segundo2;

    std::print("Entre o 1o. horario no formato HH:MM:SS ......: ");
    std::cin >> entra_hora1;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::stringstream ss1(entra_hora1);
    ss1 >> hora1 >> delimitador >> minuto1 >> delimitador >> segundo1;

    std::print("Entre o 2o. horario no formato HH:MM:SS ......: ");
    std::cin >> entra_hora2;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::stringstream ss2(entra_hora2);
    ss2 >> hora2 >> delimitador >> minuto2 >> delimitador >> segundo2;

    Time time1(hora1, minuto1, segundo1);
    Time time2(hora2, minuto2, segundo2);

    if (not time1.is_valid() or not time2.is_valid()) {
        std::println("Um ou ambos os horarios sao invalidos!");
    } else {
        uint32_t segundos1 = time1.to_seconds();
        uint32_t segundos2 = time2.to_seconds();

        int32_t diferenca_segundos =
            static_cast<int32_t>(segundos2) - static_cast<int32_t>(segundos1);
        std::string diferenca_hora = Time::from_seconds(std::abs(diferenca_segundos));

        std::println("Diferenca de tempo entre os dois horarios ....: {}", diferenca_hora);
    }

    std::println("");
    std::print("Tecle <Enter> para encerrar... ");
    std::cin.get();

    return 0;
}
