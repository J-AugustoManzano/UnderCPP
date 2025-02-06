// c07ex12.cpp

#include <iostream>
#include <print>
#include <thread>
#include <future>
#include <chrono>
#include <vector>

// Função que simula uma tarefa de produção
void produtor(std::promise<int16_t> promessa) {
    std::this_thread::sleep_for(std::chrono::seconds(2)); // Simula cálculo
    int16_t resultado = 42; // Resultado da tarefa
    std::println("Produtor ......: Gerou o valor {}", resultado);
    promessa.set_value(resultado); // Envia o resultado
}

// Função que consome o resultado (pode ser usada por múltiplas threads)
void consumidor(std::shared_future<int16_t> futuro, int16_t id) {
    int16_t valor = futuro.get(); // Obtém o resultado
    std::println("Consumidor {} ..: Recebeu o valor {}", id, valor);
}

int main(void) {
    // Criação de std::promise e std::future associados
    std::promise<int16_t> promessa;
    std::future<int16_t> futuro = promessa.get_future();

    // Transformação do std::future em std::shared_future
    std::shared_future<int16_t> futuroCompartilhado = futuro.share();

    // Lançamento da thread do produtor
    std::thread threadProdutor(produtor, std::move(promessa));

    // Lançamento de várias threads consumidoras
    const int16_t numConsumidores = 3;
    std::vector<std::thread> consumidores;
    for (size_t i = 0; i < numConsumidores; ++i) {
        consumidores.emplace_back(consumidor, futuroCompartilhado, i + 1);
    }

    // Aguarda todas as threads concluírem
    threadProdutor.join();
    for (std::thread& thr : consumidores) {
        thr.join();
    }

    std::println("");
    std::print("Tecle <Enter> para encerrar... ");
    std::cin.get();

    return 0;
}

