// c07ex08.cpp

#include <iostream>
#include <print>
#include <thread>
#include <mutex>
#include <chrono>
#include <atomic> // Para std::atomic

std::mutex resource_mutex;
std::atomic<bool> pararThreads(false); // Sinalizador para parar as threads

void tarefa_alta_prioridade(void) {
    while (not pararThreads.load()) { // Verifica se deve parar
        std::lock_guard<std::mutex> lock(resource_mutex);
        std::println("Thread de alta prioridade esta usando o recurso.");
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    }
}

void tarefa_baixa_prioridade(void) {
    while (not pararThreads.load()) { // Verifica se deve parar
        if (resource_mutex.try_lock()) {
            std::println("Thread de baixa prioridade conseguiu usar o recurso!");
            resource_mutex.unlock();
        } else {
            std::println("Thread de baixa prioridade continua esperando.");
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(2500));
    }
}

int main(void) {
    std::thread tarefaAlta(tarefa_alta_prioridade);
    std::thread tarefaBaixa(tarefa_baixa_prioridade);

    std::println("Tecle <Enter> para interromper tarefas...\n");
    std::cin.get(); // Aguarda o usuário pressionar Enter

    pararThreads.store(true); // Sinaliza para as threads pararem

    tarefaAlta.join(); // Aguarda a finalização das threads
    tarefaBaixa.join();

    std::println("");
    std::print("Tecle <Enter> para encerrar... ");
    std::cin.get();

    return 0;
}

