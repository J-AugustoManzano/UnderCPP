// c07ex02.cpp

#include <iostream>
#include <print>
#include <thread>

int contador = 0;

void incrementar(void) {
    for (int32_t i = 0; i < 1000000; ++i) {
        contador++;  // Acesso não sincronizado a uma variável compartilhada
    }
}

int main(void) {
    std::thread t1(incrementar);
    std::thread t2(incrementar);

    t1.join();
    t2.join();

    std::println("Valor final do contador: {}", contador);  // Resultado incorreto

    std::println("");
    std::print("Tecle <Enter> para encerrar... ");
    std::cin.get();

    return 0;
}
