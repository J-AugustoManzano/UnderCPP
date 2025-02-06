// c04ex16.cpp
// Somente para WinAPI

#include <iostream>
#include <print>
#include "ecrawin.h"

int main(void) {
    ecra::clrscr();
    std::println("Teste de padrao de Colores com Codigo Numerico");
    ecra::normal();
    std::print("\n");

    // Testes com cores
    ecra::color(ecra::Color::blue, ecra::Color::yellow);
    std::print("Fundo: Azul // Texto: Amarelo\n");
    ecra::normal();
    std::print("\n");

    ecra::color(ecra::Color::blue, ecra::Color::lgray);
    std::print("Fundo: Azul // Texto: Cinza claro\n");
    ecra::normal();
    std::print("\n");

    ecra::color(ecra::Color::red, ecra::Color::yellow);
    std::print("Fundo: Vermelho // Texto: Amarelo\n");
    ecra::normal();
    std::print("\n");

    ecra::color(ecra::Color::black, ecra::Color::green);
    std::print("Fundo: Preto // Texto: Verde\n");
    ecra::normal();
    std::print("\n");

    ecra::color(ecra::Color::lgray, ecra::Color::lred);
    std::print("Fundo: Cinza claro // Texto: Vermelho claro\n");
    ecra::normal();
    std::print("\n");

    ecra::color(ecra::Color::brown, ecra::Color::white);
    std::print("Fundo: Marrom // Texto: Branco\n");
    ecra::normal();
    std::print("\n");

    ecra::position(23, 1);
    std::print("\n");
    std::print("Tecle <Enter> para encerrar... ");
    std::cin.get();

    return 0;
}
