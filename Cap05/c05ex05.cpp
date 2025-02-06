// c05ex05.cpp

#include <iostream>
#include <print>

// Classe base
class A {
public:
    void exibir(void) const {
        std::println("Metodo da classe A");
    }
};

// Heran�a virtual p�blica
class B : virtual public A {};
class C : virtual public A {};

// Classe derivada final
class D : public B, public C {};

int main(void) {
    D obj;

    obj.exibir(); // Funciona porque a heran�a � p�blica

    std::println("");
    std::print("Tecle <Enter> para encerrar... ");
    std::cin.get();

    return 0;
}
