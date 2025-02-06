// c02ex30.cpp

#include <iostream>
#include <limits>
#include <print>

int main(void) {
    float a, b, c;

    std::print("Entre o lado <A>: ");
    std::cin >> a;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::print("Entre o lado <B>: ");
    std::cin >> b;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::print("Entre o lado <C>: ");
    std::cin >> c;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    if (a < b + c and b < a + c and c < a + b) {
        if (a == b and b == c) {
            std::println("Triangulo equilatero.");
        } else {
            if (a == b or a == c or b == c) {
                std::println("Triangulo isoscele.");
            } else {
                std::println("Triangulo escaleno.");
            }
        }
    } else {
        std::println("Os valores fornecidos nao formam um triangulo.");
    }

    std::println("");
    std::print("Tecle <Enter> para encerrar... ");
    std::cin.get();

    return 0;
}
