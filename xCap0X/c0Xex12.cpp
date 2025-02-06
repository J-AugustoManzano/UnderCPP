// c0Xex12.cpp

#include <iostream>
#include <print>
#include <random>
#include <set>

int main(void) {
    // Usando std::random_device como fonte de entropia
    std::random_device rd;

    // Inicializando o gerador Mersenne Twister com a semente do random_device
    std::mt19937 gen(rd());

    // Definindo a distribui��o uniforme para n�meros de ponto flutuante entre 0 e
    // 1
    std::uniform_real_distribution<> dist(0.0, 1.0);

    // Conjunto para armazenar n�meros sorteados e garantir que n�o se repitam
    std::set<double> sorteados;

    // N�mero de sorteios desejados
    int16_t quantidade_sorteios = 10;

    // Sorteando n�meros e garantindo que n�o sejam repetidos
    while (sorteados.size() < quantidade_sorteios) {
        // Sorteando um n�mero aleat�rio
        double numero = dist(gen);

        // Tentando adicionar o n�mero ao conjunto. Se j� existir, vai tentar outro.
        sorteados.insert(numero);
    }

    // Exibindo os n�meros sorteados
    std::println("Numeros sorteados (sem repeticoes):\n");
    for (double num : sorteados) {
        std::println("{:>.16}", num);
    }

    std::println("");
    std::print("Tecle <Enter> para encerrar... ");
    std::cin.get();

    return 0;
}
