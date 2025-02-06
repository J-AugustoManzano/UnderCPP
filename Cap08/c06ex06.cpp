// c08ex06.cpp

#include <iostream>
#include <print>
#include <functional>
#include <thread>
#include <chrono>

int main(void) {
    int16_t contador = 0;  // Vari�vel que ser� capturada pela lambda

    // Fun��o lambda que captura a vari�vel 'contador' por refer�ncia
    std::function<void()> temporizador = [&contador]() {
        // Simulando uma tarefa ass�ncrona (por exemplo, um temporizador de 2 segundos)
        std::this_thread::sleep_for(std::chrono::seconds(2));
        std::println("Valor do contador no temporizador: {}", contador);
    };

    // Modificando a vari�vel 'contador' antes de iniciar o temporizador
    contador = 5;
    std::println("Valor do contador antes do temporizador: {}", contador);

    // Criando uma thread para executar a fun��o lambda de forma ass�ncrona
    std::thread temp(temporizador);

    // Esperando o t�rmino da thread
    temp.join();

    // Ap�s o temporizador, o valor de 'contador' na lambda reflete a altera��o
    contador = 10;
    std::println("Valor de contador apos o temporizador: {}", contador);

    std::println("");
    std::print("Tecle <Enter> para encerrar... ");
    std::cin.get();

    return 0;
}
