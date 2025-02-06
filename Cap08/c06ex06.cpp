// c08ex06.cpp

#include <iostream>
#include <print>
#include <functional>
#include <thread>
#include <chrono>

int main(void) {
    int16_t contador = 0;  // Variável que será capturada pela lambda

    // Função lambda que captura a variável 'contador' por referência
    std::function<void()> temporizador = [&contador]() {
        // Simulando uma tarefa assíncrona (por exemplo, um temporizador de 2 segundos)
        std::this_thread::sleep_for(std::chrono::seconds(2));
        std::println("Valor do contador no temporizador: {}", contador);
    };

    // Modificando a variável 'contador' antes de iniciar o temporizador
    contador = 5;
    std::println("Valor do contador antes do temporizador: {}", contador);

    // Criando uma thread para executar a função lambda de forma assíncrona
    std::thread temp(temporizador);

    // Esperando o término da thread
    temp.join();

    // Após o temporizador, o valor de 'contador' na lambda reflete a alteração
    contador = 10;
    std::println("Valor de contador apos o temporizador: {}", contador);

    std::println("");
    std::print("Tecle <Enter> para encerrar... ");
    std::cin.get();

    return 0;
}
