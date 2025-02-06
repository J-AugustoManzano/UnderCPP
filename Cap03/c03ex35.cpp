// c03ex35.cpp

#include <iostream>
#include <print>
#include <limits>

int main(void) {
    int16_t arranjo[] = {10, 20, 30, 40, 50};
    int16_t* ptr1 = &arranjo[1]; // Aponta para o 2o. elemento (20)
    int16_t* ptr2 = &arranjo[3]; // Aponta para o 4o. elemento (40)

    std::println("Conteudo do arranjo: ");
    std::println("");
    for (size_t i = 0; i <= 4; ++i) {
        std::println("{} no indice [{}], ou seja {}o. elemento", arranjo[i], i, i + 1);
    }
    std::println("");

    std::println("Enderecos iniciais:");
    std::println("");
    std::println("ptr1 -> Valor: {} (Endereco: {:p})", *ptr1, static_cast<void*>(ptr1));
    std::println("ptr2 -> Valor: {} (Endereco: {:p})", *ptr2, static_cast<void*>(ptr2));
    std::println("");

    // Comparando os ponteiros
    if (ptr1 == ptr2) {
        std::println("ptr1 e ptr2 apontam para o mesmo endereco.");
    } else if (ptr1 < ptr2) {
        std::println("ptr1 aponta para endereco anterior ao de ptr2.");
    } else {
        std::println("ptr1 aponta para endereco posterior ao de ptr2.");
    }

    // Iterando sobre os elementos usando ponteiros
    std::println("");
    std::println("Percorrendo o arranjo usando ptr1:");
    std::println("");

    for (int16_t* p = ptr1; p <= ptr2; ++p) {
        std::println("Endereco: {:p} Valor: {}", static_cast<void*>(p), *p);
    }

    std::println("");
    std::print("Tecle <Enter> para encerrar... ");
    std::cin.get();

    return 0;
}
