// c08ex05.cpp

#include <iostream>
#include <print>
#include <functional>

int main(void) {
    int16_t x = 10;  // Vari�vel externa ao escopo da lambda
    std::println("O valor de \"x\" inicial com .....: {}", x);

    // Fun��o lambda que captura a vari�vel x
    std::function<void()> closure = [x]() {
        std::println("O valor de \"x\" no clousure .....: {}", x);
    };

    // Chamada da fun��o lambda, que ainda tem acesso a x
    closure();  // Sa�da: O valor de x �: 10

    // Mesmo depois de modificar x fora do closure, a lambda mant�m o valor de x que foi capturado
    x = 20;
    std::println("O valor de \"x\" foi atualizado ..: {}", x);
    closure();  // Sa�da: O valor de x �: 10

    std::println("");
    std::print("Tecle <Enter> para encerrar... ");
    std::cin.get();

    return 0;
}
