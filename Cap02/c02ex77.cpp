// c02ex77.cpp

#include <iostream>
#include <limits>
#include <print>

double calcularArea(double comprimento, double largura = 5.0) {
    return comprimento * largura; // Calcula e retorna a área
}

int main(void) {
    double comprimento;

    std::println("CALCULO: AREA DO RETANGULO");
    std::println("--------------------------");
    std::println("");

    std::print("Entre o o comprimento do retangulo ..: ");
    std::cin >> comprimento;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    double area1 = calcularArea(comprimento, 10.0);
    std::println("Area com largura 10.0 ...............: {}", area1);

    // Chamando a função com um único parâmetro
    double area2 = calcularArea(comprimento);
    std::println("Area com largura padrao (5.0) .......: {}", area2);


    std::println("");
    std::print("Tecle <Enter> para encerrar... ");
    std::cin.get();

    return 0;
}
