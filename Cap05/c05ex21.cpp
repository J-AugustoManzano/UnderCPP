// c05ex21.cpp

#include <iostream>
#include <print>

struct Numero {
public:
    explicit Numero(int16_t n) : valor(n) {}

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
    // mostrarNumero(10);  // Erro de compilação! Conversão implícita não permitida

    // Agora é necessário criar explicitamente o objeto Numero
    mostrarNumero(Numero(10));

    std::println("");
    std::print("Tecle <Enter> para encerrar... ");
    std::cin.get();

    return 0;
}
