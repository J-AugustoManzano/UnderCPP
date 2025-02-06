// c02ex04.cpp

#include <iostream>
#include <cmath> // Para fun��es matem�ticas

int main() {
    // Constantes expl�citas
    constexpr double PI = 3.14159;
    const double raio = 10.0;

    // C�lculo da circunfer�ncia
    double circunferencia = 2 * PI * raio;

    // C�lculo da �rea usando a fun��o da biblioteca cmath e constante expl�cita
    double area = PI * std::pow(raio, 2);

    // Usando fun��es da cmath para calcular a raiz quadrada
    double raizQuadrada = std::sqrt(area);

    std::cout << "Circunferencia .........: " << circunferencia << std::endl;
    std::cout << "Area ...................: " << area << std::endl;
    std::cout << "Raiz quadrada da area ..: " << raizQuadrada << std::endl;

    std::cout << std::endl;
    std::cout << "Tecle <Enter> para encerrar... ";
    std::cin.get();

    return 0;
}
