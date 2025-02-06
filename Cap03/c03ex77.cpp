// c03ex77.cpp

#include <iostream>
#include <print>
#include <iostream>

namespace meu_espaco {
    void saudacao(void) {
        std::println("Olá do meu_espaco!");
    }
}

using namespace meu_espaco;  // Torna os nomes do namespace acessíveis diretamente

int main(void) {
    saudacao();  // Não precisa de 'meu_espaco::' antes da função greet

    std::println("");
    std::print("Tecle <Enter> para encerrar... ");
    std::cin.get();

    return 0;
}
