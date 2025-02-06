// c07ex11.cpp

#include <iostream>
#include <print>
#include <thread>
#include <future>
#include <chrono>

// Tarefa de alta prioridade
int16_t tarefa_alta_prioridade() {
    std::this_thread::sleep_for(std::chrono::seconds(1));
    std::println("Alta prioridade: tarefa concluida.");
    return 42; // Exemplo de resultado
}

// Tarefa de baixa prioridade
int16_t tarefa_baixa_prioridade() {
    std::this_thread::sleep_for(std::chrono::seconds(2));
    std::println("Baixa prioridade: tarefa concluida.");
    return 7; // Exemplo de resultado
}

int main(void) {
    std::println("Tarefas iniciadas...");
    std::println("");

    // Lançando tarefas assíncronas
    std::future<int16_t> resultadoAlta = std::async(std::launch::async, tarefa_alta_prioridade);
    std::future<int16_t> resultadoBaixa = std::async(std::launch::async, tarefa_baixa_prioridade);

    // Aguardando os resultados
    std::println("Resultado alta prioridade: {}", resultadoAlta.get());
    std::println("");
    std::println("Resultado baixa prioridade: {}", resultadoBaixa.get());

    std::println("");
    std::print("Tecle <Enter> para encerrar... ");
    std::cin.get();

    return 0;
}

