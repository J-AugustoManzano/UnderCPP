// c08ex07.cpp

#include <iostream>
#include <print>
#include <limits>

// Definição da classe Calculo
class Calculo {
private:
    // Função privada que calcula o fatorial com recursão de cauda
    int64_t fatBase(const int16_t n, const int64_t resultado) {
        if (n == 0) {
            return resultado; // Caso base: fatorial de 0 é 1
        } else {
            return fatBase(n - 1, resultado * n); // Chamada recursiva
        }
    }

public:
    // Função pública que chama fatBase com valor inicial 1
    int64_t fatorial(const int16_t n) {
        return fatBase(n, 1); // Inicia a recursão com resultado = 1
    }
};

int main(void) {
    Calculo calculo;
    int16_t numero;

    std::print("Entre valor numerico inteiro: ");
    std::cin >> numero;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    const int16_t n = numero;
    std::println("Fatorial de {} = {}", n, calculo.fatorial(n));

    // Erro: 'fatBase' é um membro privado de 'Calculo', não pode ssr acessado
    // std::println("Fatorial de {} = {}", n, calculo.fatBase(n, 1));

    std::println("");
    std::print("Tecle <Enter> para encerrar... ");
    std::cin.get();

    return 0;
}
