// c02ex11.cpp

#include <iostream>
#include <string> // Para manipula��o de strings

int main(void) {
    std::string nome; // Declara��o da vari�vel para armazenar o nome

    std::cout << "Por favor, entre seu nome: ";
    std::getline(std::cin, nome); // L� a linha completa, incluindo espa�os

    std::cout << "Oi, " << nome << "! Seja bem-vindo!" << std::endl;

    std::cout << std::endl;
    std::cout << "Tecle <Enter> para encerrar... ";
    std::cin.get();

    return 0;
}
