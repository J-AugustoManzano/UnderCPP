// c02ex03.cpp

#include <iostream>
#include <numbers>  // para a constante matem�tica: pi
#include <cmath>    // Para fun��o matem�tica: pow

int main(void) {
    int16_t x = 3;
    int16_t y = 4;

    // Express�o complexa usando f�rmula do cosseno
    double resultado = (pow(x, 2) + pow(y, 2)) / (2 * x * y); // resultado = 0.5

    // Outra express�o complexa com constante impl�cita
    double areaCirculo = std::numbers::pi * pow(5, 2); // �rea de um c�rculo de raio 5

    std::cout << "Resultado da expressao ..: " << resultado << std::endl;
    std::cout << "Area do circulo .........: " << areaCirculo << std::endl;

    std::cout << std::endl;
    std::cout << "Tecle <Enter> para encerrar... ";
    std::cin.get();

    return 0;
}
