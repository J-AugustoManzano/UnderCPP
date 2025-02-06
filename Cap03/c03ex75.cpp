// c03ex75.cpp

#include <iostream>
#include <print>

// Definindo um namespace chamado "meu_calculo"
namespace meu_calculo {
    int32_t adicao(int32_t a, int32_t b) {
        return a + b;
    }

    int32_t subtracao(int32_t a, int32_t b) {
        return a - b;
    }
}

int main(void) {
    // Usando as funções dentro do namespace "meu_calculo"
    int32_t x = meu_calculo::adicao(5, 3);
    int32_t y = meu_calculo::subtracao(5, 3);

    std::println("Soma .......: {}", x);
    std::println("Diferenca ..: {}", y);

    std::println("");
    std::print("Tecle <Enter> para encerrar... ");
    std::cin.get();

    return 0;
}
