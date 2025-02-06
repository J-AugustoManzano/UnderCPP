// c07ex04.cpp

#include <iostream>
#include <print>
#include <thread>
#include <mutex>

std::mutex mtx;
int contador = 0;

void incrementar(void) {
    for (int32_t i = 0; i < 1000000; ++i) {
        std::lock_guard<std::mutex> guard(mtx);  // Bloqueia o mutex automaticamente
        contador++;
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

