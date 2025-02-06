// c07ex12.cpp

#include <iostream>
#include <print>
#include <thread>
#include <future>
#include <chrono>
#include <vector>

// Fun��o que simula uma tarefa de produ��o
void produtor(std::promise<int16_t> promessa) {
    std::this_thread::sleep_for(std::chrono::seconds(2)); // Simula c�lculo
    int16_t resultado = 42; // Resultado da tarefa
    std::println("Produtor ......: Gerou o valor {}", resultado);
    promessa.set_value(resultado); // Envia o resultado
}

// Fun��o que consome o resultado (pode ser usada por m�ltiplas threads)
void consumidor(std::shared_future<int16_t> futuro, int16_t id) {
    int16_t valor = futuro.get(); // Obt�m o resultado
    std::println("Consumidor {} ..: Recebeu o valor {}", id, valor);
}

int main(void) {
    // Cria��o de std::promise e std::future associados
    std::promise<int16_t> promessa;
    std::future<int16_t> futuro = promessa.get_future();

    // Transforma��o do std::future em std::shared_future
    std::shared_future<int16_t> futuroCompartilhado = futuro.share();

    // Lan�amento da thread do produtor
    std::thread threadProdutor(produtor, std::move(promessa));

    // Lan�amento de v�rias threads consumidoras
    const int16_t numConsumidores = 3;
    std::vector<std::thread> consumidores;
    for (size_t i = 0; i < numConsumidores; ++i) {
        consumidores.emplace_back(consumidor, futuroCompartilhado, i + 1);
    }

    // Aguarda todas as threads conclu�rem
    threadProdutor.join();
    for (std::thread& thr : consumidores) {
        thr.join();
    }

    std::println("");
    std::print("Tecle <Enter> para encerrar... ");
    std::cin.get();

    return 0;
}

