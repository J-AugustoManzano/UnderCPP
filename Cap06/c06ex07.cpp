// c06ex07.cpp

#include <iostream>
#include <print>
#include <chrono>
#include <thread>  // Para std::this_thread::sleep_for

int main(void) {
    int16_t i = 1, timer = 10;

    do {
        // Exibir mensagem
        std::println("Mensagem no segundo: {:>2}", i);

        // Aguardar 1 segundo usando chrono e thread
        std::this_thread::sleep_for(std::chrono::seconds(1));

        // Incrementar o contador
        ++i;

    } while (i <= timer);

    std::println("");
    std::print("Tecle <Enter> para encerrar... ");
    std::cin.get();

    return 0;
}

