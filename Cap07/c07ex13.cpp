// c07ex13.cpp

#include <iostream>
#include <print>
#include <thread>
#include <queue>
#include <vector>
#include <functional>
#include <mutex>
#include <condition_variable>

class ThreadPool {
private:
    std::vector<std::thread> fluxos;            // Threads do pool
    std::queue<std::function<void()>> tarefas;  // Fila de tarefas
    std::mutex mtx;                             // Mutex para proteger a fila
    std::condition_variable cv;                 // Condição para sincronizar
    bool parar;                                 // Flag para parar o pool

public:
    explicit ThreadPool(size_t numThreads) : parar(false) {
        for (size_t i = 0; i < numThreads; ++i) {
            fluxos.emplace_back([this] {
                while (true) {
                    std::function<void()> tarefa;
                    {
                        std::unique_lock<std::mutex> travar(mtx);
                        cv.wait(travar, [this] { return parar or not tarefas.empty(); });
                        if (parar and tarefas.empty()) return;
                        tarefa = std::move(tarefas.front());
                        tarefas.pop();
                    }
                    tarefa(); // Executa a tarefa
                }
            });
        }
    }

    template <typename F, typename... Args>
    void enfileirarTarefa(F&& func, Args&&... args) {
        {
            std::unique_lock<std::mutex> travar(mtx);
            tarefas.emplace([=] { func(args...); });
        }
        cv.notify_one(); // Notifica uma thread
    }

    ~ThreadPool() {
        {
            std::unique_lock<std::mutex> travar(mtx);
            parar = true;
        }
        cv.notify_all();
        for (std::thread& fluxo : fluxos) {
            if (fluxo.joinable()) fluxo.join();
        }
    }
};

// Função de exemplo
void esreveMensagem(int16_t id) {
    std::println("Thread {:>2} executando tarefa", id);
}

int main(void) {
    ThreadPool pool(4); // Pool com 4 fluxos

    for (int16_t i = 0; i <= 9; ++i) {
        pool.enfileirarTarefa(esreveMensagem, i + 1);
    }

    std::this_thread::sleep_for(std::chrono::seconds(1)); // Espera um pouco

    std::println("");
    std::print("Tecle <Enter> para encerrar... ");
    std::cin.get();

    return 0;
}

