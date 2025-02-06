// c05ex07.cpp

#include <iostream>
#include <print>

// Classe base A
class A {
public:
    void exibir(void) const {
        std::println("Metodo da classe A");
    }
};

// Classe base B
class B {
public:
    void exibir(void) const {
        std::println("Metodo da classe B");;
    }
};

// Classe derivada C herda de A e B
class C : public A, public B {
public:
    void mostrar(void) const {
        // Tentativa de chamar o método exibir()
        // exibir(); // ERRO: Ambiguidade!
        // membro 'exibir' encontrado em múltiplas classes base de tipos diferentes
    }
};

int main(void) {
    C objeto;

    objeto.mostrar();

    std::println("");
    std::print("Tecle <Enter> para encerrar... ");
    std::cin.get();

    return 0;
}
