// c03ex77.cpp

#include <iostream>
#include <print>
#include <iostream>

namespace meu_espaco {
    void saudacao(void) {
        std::println("Ol� do meu_espaco!");
    }
}

using namespace meu_espaco;  // Torna os nomes do namespace acess�veis diretamente

int main(void) {
    saudacao();  // N�o precisa de 'meu_espaco::' antes da fun��o greet

    std::println("");
    std::print("Tecle <Enter> para encerrar... ");
    std::cin.get();

    return 0;
}
