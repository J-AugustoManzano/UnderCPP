// c04ex15.cpp
// Somente para like-Unix

#include <iostream>
#include <print>
#include "ecransi.h"

int main(void) {

    ecra::clrscr();
    std::println("Teste de padrao de Colores com Codigo Numerico");
    ecra::normal();
    std::println("\n");

    ecra::color(ecra::Color::blue, ecra::Color::yellow);
    std::print("Fundo: Azul // Texto: Amarelo");
    ecra::normal();
    std::println("\n");

    ecra::color(ecra::Color::blue, ecra::Color::lgray);
    std::print("Fundo: Azul // Texto: Cinza claro");
    ecra::normal();
    std::println("\n");

    ecra::color(ecra::Color::red, ecra::Color::yellow);
    std::print("Fundo: Vermelho // Texto: Amarelo");
    ecra::normal();
    std::println("\n");

    ecra::color(ecra::Color::black, ecra::Color::green);
    std::print("Fundo: Preto // Texto: Verde");
    ecra::normal();
    std::println("\n");

    ecra::color(ecra::Color::lgray, ecra::Color::lred);
    std::print("Fundo: Cinza claro // Texto: Vermelho claro");
    ecra::normal();
    std::println("\n");

    ecra::color(ecra::Color::brown, ecra::Color::white);
    std::print("Fundo: Marrom // Texto: Branco");
    ecra::normal();
    std::println("\n");

    ecra::position(23, 1);
    std::print("\n");
    std::print("Tecle <Enter> para encerrar... ");
    std::cin.get();

    return 0;
}
