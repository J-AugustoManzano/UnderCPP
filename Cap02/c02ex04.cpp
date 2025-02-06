// c02ex04.cpp

#include <iostream>
#include <cmath> // Para funções matemáticas

int main() {
    // Constantes explícitas
    constexpr double PI = 3.14159;
    const double raio = 10.0;

    // Cálculo da circunferência
    double circunferencia = 2 * PI * raio;

    // Cálculo da área usando a função da biblioteca cmath e constante explícita
    double area = PI * std::pow(raio, 2);

    // Usando funções da cmath para calcular a raiz quadrada
    double raizQuadrada = std::sqrt(area);

    std::cout << "Circunferencia .........: " << circunferencia << std::endl;
    std::cout << "Area ...................: " << area << std::endl;
    std::cout << "Raiz quadrada da area ..: " << raizQuadrada << std::endl;

    std::cout << std::endl;
    std::cout << "Tecle <Enter> para encerrar... ";
    std::cin.get();

    return 0;
}
