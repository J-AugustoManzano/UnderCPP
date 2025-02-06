// c07ex01.cpp

#include <iostream>
#include <print>
#include <thread>

void imprimir_numeros(int id) {
    for (int16_t i = 1; i <= 5; ++i) {
        std::println("Thread {}: {}", id, i);
    }
}

int main(void) {
    // Criando duas threads
    std::thread t1(imprimir_numeros, 1);
    std::thread t2(imprimir_numeros, 2);

    // Aguardando as threads terminarem
    t1.join();
    t2.join();

    std::println("");
    std::print("Tecle <Enter> para encerrar... ");
    std::cin.get();

    return 0;
}
