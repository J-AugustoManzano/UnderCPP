// c05ex14.cpp

#include <iostream>
#include <print>

class Complex {
public:
    int32_t real, imag;

    Complex(int r, int i) : real(r), imag(i) {}

    // Sobrecarga do operador '+'
    Complex operator+(const Complex& valor) {
        return Complex(real + valor.real, imag + valor.imag);
    }

    void display(void) {
        std::println("{}+{}i", real, imag);
    }
};

int main(void) {
    Complex c1(3, 4), c2(1, 2);  // c1 = 3+4i e c2 = 1+2i
    Complex c3 = c1 + c2;  // Sobrecarga do operador '+'

    c3.display();  // Saída: 4+6i

    std::println("");
    std::print("Tecle <Enter> para encerrar... ");
    std::cin.get();

    return 0;
}
