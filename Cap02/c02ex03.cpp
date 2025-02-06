// c02ex03.cpp

#include <iostream>
#include <numbers>  // para a constante matemática: pi
#include <cmath>    // Para função matemática: pow

int main(void) {
    int16_t x = 3;
    int16_t y = 4;

    // Expressão complexa usando fórmula do cosseno
    double resultado = (pow(x, 2) + pow(y, 2)) / (2 * x * y); // resultado = 0.5

    // Outra expressão complexa com constante implícita
    double areaCirculo = std::numbers::pi * pow(5, 2); // Área de um círculo de raio 5

    std::cout << "Resultado da expressao ..: " << resultado << std::endl;
    std::cout << "Area do circulo .........: " << areaCirculo << std::endl;

    std::cout << std::endl;
    std::cout << "Tecle <Enter> para encerrar... ";
    std::cin.get();

    return 0;
}
