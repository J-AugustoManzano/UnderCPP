// c04ex20.cpp

#include <iostream>
#include <limits>
#include <stdexcept>
#include <print>

// Função para calcular o dobro com checagem manual de overflow
int32_t calcDobro(int16_t x) {
    // Verifica se x é negativo
    if (x < 0) {
        throw std::invalid_argument("Argumento negativo.");
    }

    // Verificar se o dobro vai ultrapassar o limite do int16_t
    if (x > std::numeric_limits<int16_t>::max() / 2) {
        throw std::overflow_error("Overflow ao calcular o dobro.");
    }

    return x * 2;
}

int main(void) {
    int16_t numero;
    int32_t resultado;

    std::cout << "Entre um numero positivo: ";
    std::cin >> numero;

    try {
        resultado = calcDobro(numero);
        std::println("O dobro de {} = {}", numero, resultado);
    } catch (const std::invalid_argument& e) {
        std::cerr << "Erro: " << e.what() << std::endl;
    } catch (const std::overflow_error& e) {
        std::cerr << "Erro: " << e.what() << std::endl;
    }
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::println("");
    std::print("Tecle <Enter> para encerrar... ");
    std::cin.get();

    return 0;
}
