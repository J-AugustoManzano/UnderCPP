// c02ex76.cpp

#include <iostream>
#include <limits>
#include <print>

int32_t divInteiro(int32_t dividendo, int32_t divisor, int16_t &resto) {
    resto = dividendo % divisor;  // Calcula o resto para referência
    return dividendo / divisor;   // Calcula o quociente para retorno
}

int main(void) {
    int16_t dividendo, divisor, quociente, resto;

    std::println("CALCULO DA DIVISAO DE INTEIROS");
    std::println("------------------------------");
    std::println("");

    std::print("Entre o valor numerico inteiro do dividendo ..: ");
    std::cin >> dividendo;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::print("Entre o valor numerico inteiro do divisor ....: ");
    std::cin >> divisor;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    quociente = divInteiro(dividendo, divisor, resto);

    std::println("");
    std::println("Quociente ..: {}", quociente);
    std::println("Resto ......: {}", resto);

    std::println("");
    std::print("Tecle <Enter> para encerrar... ");
    std::cin.get();

    return 0;
}
