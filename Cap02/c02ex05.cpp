// c02ex05.cpp

#include <iostream>

int main(void) {
    int16_t a = 10;
    int16_t b = 5;

    // Operadores relacionais
    bool igual = (a == b);         // false
    bool diferente = (a != b);     // true
    bool maior = (a > b);          // true
    bool menor = (a < b);          // false
    bool maiorOuIgual = (a >= b);  // true
    bool menorOuIgual = (a <= b);  // false

    // Exibindo os resultados das comparações
    std::cout << "a == b ..: " << igual << std::endl;
    std::cout << "a != b ..: " << diferente << std::endl;
    std::cout << "a > b ...: " << maior << std::endl;
    std::cout << "a < b ...: " << menor << std::endl;
    std::cout << "a >= b ..: " << maiorOuIgual << std::endl;
    std::cout << "a <= b ..: " << menorOuIgual << std::endl;

    std::cout << std::endl;
    std::cout << "Tecle <Enter> para encerrar... ";
    std::cin.get();

    return 0;
}
