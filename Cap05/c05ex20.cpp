// c05ex20.cpp

#include <iostream>
#include <print>

struct Numero {
public:
    Numero(int16_t n) : valor(n) {}

    void exibirValor() const {
        std::println("Valor: {}", valor);
    }

private:
    int16_t valor;
};

void mostrarNumero(Numero n) {
    n.exibirValor();
}

int main(void) {
    // O int16_t 10 será convertido implicitamente para o tipo Numero
    mostrarNumero(10);

    std::println("");
    std::print("Tecle <Enter> para encerrar... ");
    std::cin.get();

    return 0;
}
