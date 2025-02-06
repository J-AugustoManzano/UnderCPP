// c07ex09.cpp

#include <iostream>
#include <print>
#include <thread>
#include <mutex>
#include <chrono>
#include <atomic>
#include <condition_variable>

// Recursos compartilhados
std::mutex resource_mutex;
std::condition_variable cv;
std::atomic<bool> pararThreads(false);
bool recurso_disponivel = true; // Estado do recurso

void tarefa_alta_prioridade(void) {
    while (not pararThreads.load()) {
        std::unique_lock<std::mutex> lock(resource_mutex);

        // Espera o recurso ficar disponível
        cv.wait(lock, [] { return recurso_disponivel; });

        // Usa o recurso
        recurso_disponivel = false; // Marca como ocupado
        std::println("Thread de alta prioridade esta usando o recurso.");
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));

        // Libera o recurso e notifica
        recurso_disponivel = true;
        cv.notify_one(); // Notifica outra thread
    }
}

void tarefa_baixa_prioridade(void) {
    while (not pararThreads.load()) {
        std::unique_lock<std::mutex> lock(resource_mutex);

        // Espera o recurso ficar disponível
        cv.wait(lock, [] { return recurso_disponivel; });

        // Usa o recurso
        recurso_disponivel = false; // Marca como ocupado
        std::println("Thread de baixa prioridade conseguiu usar o recurso!");
        std::this_thread::sleep_for(std::chrono::milliseconds(2500));

        // Libera o recurso e notifica
        recurso_disponivel = true;
        cv.notify_one(); // Notifica outra thread
    }
}

int main(void) {
    std::thread tarefaAlta(tarefa_alta_prioridade);
    std::thread tarefaBaixa(tarefa_baixa_prioridade);

    std::println("Tecle <Enter> para interromper tarefas...\n");
    std::cin.get(); // Aguarda o usuário pressionar Enter

    pararThreads.store(true); // Sinaliza para as threads pararem
    cv.notify_all(); // Desperta todas as threads para finalizar

    tarefaAlta.join();
    tarefaBaixa.join();

    std::println("");
    std::print("Tecle <Enter> para encerrar... ");
    std::cin.get();

    return 0;
}

