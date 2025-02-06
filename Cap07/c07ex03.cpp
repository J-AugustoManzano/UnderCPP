// c07ex03.cpp

#include <iostream>
#include <print>
#include <thread>
#include <mutex>

std::mutex mtx;  // Mutex para sincronizar o acesso
int contador = 0;

void incrementar(void) {
    for (int32_t i = 0; i < 1000000; ++i) {
        mtx.lock();  // Bloqueia o mutex antes de acessar a variável compartilhada
        contador++;  // Acesso seguro à variável compartilhada
        mtx.unlock();  // Libera o mutex
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
