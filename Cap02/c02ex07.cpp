// c02ex07.cpp

#include <iostream>

int main(void) {
    bool a = true;
    bool b = false;

    // Usando operadores lógicos
    bool resultadoAnd = a and b;  // false (true AND false)
    bool resultadoOr = a or b;    // true (true OR false)
    bool resultadoXor = a xor b;  // true (true XOR false)
    bool resultadoNotA = not a;   // false (NOT true)
    bool resultadoNotB = not b;   // true (NOT false)

    // Exibindo os resultados
    std::cout << "a AND b ..: " << std::boolalpha << resultadoAnd << std::endl;
    std::cout << "a OR b ...: " << resultadoOr << std::endl;
    std::cout << "a XOR b ..: " << resultadoXor << std::endl;
    std::cout << "NOT a ....: " << resultadoNotA << std::endl;
    std::cout << "NOT b ....: " << resultadoNotB << std::endl;

    std::cout << std::noboolalpha;

    std::cout << std::endl;
    std::cout << "Tecle <Enter> para encerrar... ";
    std::cin.get();

    return 0;
}
