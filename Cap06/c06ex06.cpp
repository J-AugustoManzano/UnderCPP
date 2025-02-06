// c06ex06.cpp

#include <iostream>
#include <chrono>
#include <print>

// Função recursiva simples para calcular Fibonacci
uint64_t fib_simples(uint16_t n) {
    if (n <= 1) return n;
    return fib_simples(n - 1) + fib_simples(n - 2);
}

// Função recursiva de cauda para calcular Fibonacci
uint64_t fib_cauda(uint16_t n, uint64_t a = 0, uint64_t b = 1) {
    if (n == 0) return a;
    if (n == 1) return b;
    return fib_cauda(n - 1, b, a + b);
}

int main(void) {

    // Exibir o cabeçalho do relatório
    std::println("Benchmark: Comparacao Recursao Simples x Cauda");
    std::println("----------------------------------------------\n");
    std::println("{:<5} {:<24} {:<24}\n", "Termo", "Fibonacci Simples", "Fibonacci Cauda");

    // Laço para calcular e comparar os tempos de Fibonacci simples e de cauda
    for (uint16_t termo = 25; termo <= 40; ++termo) {
        // Cronometrar Fibonacci simples
        auto inicioTempoSimples = std::chrono::high_resolution_clock::now();
        fib_simples(termo);
        auto fimTempoSimples = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> tempoSimples = fimTempoSimples - inicioTempoSimples;

        // Cronometrar Fibonacci cauda
        auto start_time_tail = std::chrono::high_resolution_clock::now();
        fib_cauda(termo);
        auto end_time_tail = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> tempoCauda = end_time_tail - start_time_tail;

        // Exibir resultados lde tempo
        std::print("{:>5} {:<24.2f} {:<24.2f}\n",
            termo, tempoSimples.count(), tempoCauda.count());
    }

    std::println("");
    std::println("Benchmark concluido.");

    std::println("");
    std::print("Tecle <Enter> para encerrar... ");
    std::cin.get();

    return 0;
}

