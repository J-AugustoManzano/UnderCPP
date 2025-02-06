// c07ex10.cpp

#include <iostream>
#include <print>
#include <thread>
#include <mutex>
#include <chrono>
#include <atomic>

std::timed_mutex resource_mutex;
std::atomic<bool> pararThreads(false);

void tarefa_alta_prioridade(void) {
    while (not pararThreads.load()) {
        if (resource_mutex.try_lock_for(std::chrono::milliseconds(500))) {
            // Recurso adquirido
            std::println("Thread de alta prioridade esta usando o recurso.");
            std::this_thread::sleep_for(std::chrono::milliseconds(1000));
            resource_mutex.unlock(); // Libera o recurso
        } else {
            // Não conseguiu o recurso
            std::println("Thread de alta prioridade nao conseguiu o recurso, aguardando...");
        }
    }
}

void tarefa_baixa_prioridade(void) {
    while (not pararThreads.load()) {
        if (resource_mutex.try_lock_for(std::chrono::milliseconds(1500))) {
            // Recurso adquirido
            std::println("Thread de baixa prioridade conseguiu usar o recurso!");
            std::this_thread::sleep_for(std::chrono::milliseconds(2500));
            resource_mutex.unlock(); // Libera o recurso
        } else {
            // Não conseguiu o recurso
            std::println("Thread de baixa prioridade nao conseguiu o recurso, aguardando...");
        }
    }
}

int main(void) {
    std::thread tarefaAlta(tarefa_alta_prioridade);
    std::thread tarefaBaixa(tarefa_baixa_prioridade);

    std::println("Tecle <Enter> para interromper tarefas...\n");
    std::cin.get(); // Aguarda o usuário pressionar Enter

    pararThreads.store(true); // Sinaliza para as threads pararem

    tarefaAlta.join();
    tarefaBaixa.join();

    std::println("");
    std::print("Tecle <Enter> para encerrar... ");
    std::cin.get();

    return 0;
}

