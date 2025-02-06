// c03ex76.cpp

#include <iostream>
#include <print>

namespace area1 {
    void exibicao(void) {
        std::println("Namespaca: area1");
    }
}

namespace area2 {
    void exibicao(void) {
        std::println("Namespaca: area2");
    }
}

int main(void) {
    // Usando as sub-rotinas de dois namespaces diferentes
    area1::exibicao();
    area2::exibicao();

    std::println("");
    std::print("Tecle <Enter> para encerrar... ");
    std::cin.get();

    return 0;
}
