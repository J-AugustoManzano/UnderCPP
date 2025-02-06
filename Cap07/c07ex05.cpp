// c07ex05.cpp

#include <iostream>
#include <print>
#include <thread>
#include <mutex>

std::mutex mtx;
int contador = 0;

void incrementar(void) {
    std::unique_lock<std::mutex> lock(mtx);
    for (int32_t i = 0; i < 1000000; ++i) {
        contador++;
    }
    // O mutex será liberado automaticamente quando 'lock' sair de escopo
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

