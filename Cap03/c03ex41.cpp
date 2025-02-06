// c03ex41.cpp

#include <iostream>
#include <print>
#include <limits>

int main(void) {
    // Temperatura atual a ser monitorada
    int16_t temperaturaAtual = 25;
    int16_t novaTemperatura = 0;
    int16_t outraTemperatura = 30;

    int16_t* const ptrTemperatura = &temperaturaAtual;

    // Exibe valor da temperatural atual
    std::println("Temperatura atual: {} graus Celcius", *ptrTemperatura);

    // Alteração do valor apontado
    std::print("Entre a nova temperatura: ");
    std::cin >> novaTemperatura;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    // Atualiza o valor apontado
    *ptrTemperatura = novaTemperatura;
    std::println("Temperatura atualizada: {} gruas Celcius", *ptrTemperatura);

    // Tentativa de redirecionar o ponteiro para outro endereço

    // Descomente as linhaa a seguir para ver o erro de compilação que ocorre
    // std::println("");
    // std::println("Tentativa de redirecionar o ponteiro para outro endereco...");
    // ptrTemperatura = &outraTemperatura; // Erro de compilação
    // std::println("Erro: Ponteiro constante nao pode ser redirecionado a outro endereco.");

    std::println("");
    std::print("Tecle <Enter> para encerrar... ");
    std::cin.get();

    return 0;
}
