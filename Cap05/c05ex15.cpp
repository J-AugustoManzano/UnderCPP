// c05ex15.cpp

#include <iostream>
#include <print>

class Complex {
private:
    int real, imag; // Partes real e imaginária do número complexo

public:
    // Construtor parametrizado
    Complex(int r, int i) : real(r), imag(i) {}

    // Método para somar dois números complexos
    Complex adicao(const Complex& valor) {
        return Complex(real + valor.real, imag + valor.imag);
    }

    // Método para imprimir um número complexo
    void mostrar(void) const {
        std::println("{}+{}i", real, imag);
    }
};

int main(void) {
    // Criação de dois números complexos
    Complex c1(3, 4); // Número complexo 3 + 4i
    Complex c2(1, 2); // Número complexo 1 + 2i

    // Usando o método 'add' para somar c1 e c2
    Complex c3 = c1.adicao(c2);

    // Imprimindo o resultado
    std::print("Resultado da soma: ");
    c3.mostrar(); // Saída esperada: 4 + 6i

    std::println("");
    std::print("Tecle <Enter> para encerrar... ");
    std::cin.get();

    return 0;
}
