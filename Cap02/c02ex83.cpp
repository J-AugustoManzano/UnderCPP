// c02ex83.cpp

#include <iostream>
#include <limits>
#include <print>

int64_t calcArea(int64_t X) { // Area: quadrado
    return X * X;
}

double calcArea(float R, float H) { // Area: cilindro
    return  R * R * 3.14159 * H;;
}

int64_t calcArea(int64_t X, int64_t Y, int64_t Z) { // Area: Cubo
    return  X * Y * Z;
}

int main(void) {
    int16_t x, y;

    std::println("SOBRECARGA DE SUB-ROTINAS");
    std::println("-------------------------");
    std::println("");

    std::println("rea: Quadrado ...: {}", calcArea(5));
    std::println("Area: Cubo ......: {}", calcArea(5, 6, 7));
    std::println("Area: Cilindro ..: {}", calcArea(7, 3));

    std::println("");
    std::print("Tecle <Enter> para encerrar... ");
    std::cin.get();

    return 0;
}

