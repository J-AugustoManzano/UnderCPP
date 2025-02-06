// c0Xex11.cpp

#include <iostream>
#include <print>
#include <random>

int main(void) {
    // Usando std::random_device como fonte de entropia
    std::random_device rd;

    // Inicializando o gerador Mersenne Twister com uma semente imprevis�vel
    std::mt19937 gen(rd());

    // Definindo uma distribui��o uniforme entre 1 e 100
    std::uniform_int_distribution<> dist(1, 100);

    // Gerando e exibindo n�meros aleat�rios
    for (int16_t i = 0; i <= 9; ++i) {
        std::println("{:>3}", dist(gen));
    }

    std::println("");
    std::print("Tecle <Enter> para encerrar... ");
    std::cin.get();

    return 0;
}
