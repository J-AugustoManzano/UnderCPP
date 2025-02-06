// c05ex11.cpp

#include <iostream>
#include <print>
#include <cmath>
#include <numbers>

class Carea {
public:
    int64_t pegArea(int16_t x) {  // Area: quadrado
        return pow(x, 2);;
    }

    double pegArea(float r, float h) {  // Area: cilindro
        return pow(r, 2) * std::numbers::pi * h;
    }

    int64_t pegArea(int16_t x, int16_t y, int16_t z) {  // Area: Cubo
        return x * y * z;
    }
};

int main(void) {
    Carea calc;
    std::println("Area: Quadrado ..: {:>4}", calc.pegArea(5));
    std::println("Area: Cubo ......: {:>4}", calc.pegArea(5, 6, 7));
    std::println("Area: Cilindro ..: {:>7.2f}", calc.pegArea(7, 3));

    std::println("");
    std::print("Tecle <Enter> para encerrar... ");
    std::cin.get();

    return 0;
}
