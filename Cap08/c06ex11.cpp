// c08ex11.cpp

#include <iostream>
#include <print>
#include <functional>

// Fun��o que efetua a multiplica��o
auto multiplicar = [](int16_t x, int16_t y) {
    return x * y;
};

// Fun��o simulada para multiplica��o
auto multiplicarPor = [](int16_t x) {
    return [x](int16_t y) { return multiplicar(x, y); };
};

int main(void) {
    // Fun��o currficada espec�fica para multiplicar por 10
    auto multiplicarPorDez = multiplicarPor(10);

    // Usando a fun��o multiplicarPorDez
    std::println("Resultado: {}", multiplicarPorDez(5)); // Sa�da: 50

    std::println("");
    std::print("Tecle <Enter> para encerrar... ");
    std::cin.get();

    return 0;
}
