// c05ex15.cpp

#include <iostream>
#include <print>

class Complex {
private:
    int real, imag; // Partes real e imagin�ria do n�mero complexo

public:
    // Construtor parametrizado
    Complex(int r, int i) : real(r), imag(i) {}

    // M�todo para somar dois n�meros complexos
    Complex adicao(const Complex& valor) {
        return Complex(real + valor.real, imag + valor.imag);
    }

    // M�todo para imprimir um n�mero complexo
    void mostrar(void) const {
        std::println("{}+{}i", real, imag);
    }
};

int main(void) {
    // Cria��o de dois n�meros complexos
    Complex c1(3, 4); // N�mero complexo 3 + 4i
    Complex c2(1, 2); // N�mero complexo 1 + 2i

    // Usando o m�todo 'add' para somar c1 e c2
    Complex c3 = c1.adicao(c2);

    // Imprimindo o resultado
    std::print("Resultado da soma: ");
    c3.mostrar(); // Sa�da esperada: 4 + 6i

    std::println("");
    std::print("Tecle <Enter> para encerrar... ");
    std::cin.get();

    return 0;
}
