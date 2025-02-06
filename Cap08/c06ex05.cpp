// c08ex05.cpp

#include <iostream>
#include <print>
#include <functional>

int main(void) {
    int16_t x = 10;  // Variável externa ao escopo da lambda
    std::println("O valor de \"x\" inicial com .....: {}", x);

    // Função lambda que captura a variável x
    std::function<void()> closure = [x]() {
        std::println("O valor de \"x\" no clousure .....: {}", x);
    };

    // Chamada da função lambda, que ainda tem acesso a x
    closure();  // Saída: O valor de x é: 10

    // Mesmo depois de modificar x fora do closure, a lambda mantém o valor de x que foi capturado
    x = 20;
    std::println("O valor de \"x\" foi atualizado ..: {}", x);
    closure();  // Saída: O valor de x é: 10

    std::println("");
    std::print("Tecle <Enter> para encerrar... ");
    std::cin.get();

    return 0;
}
