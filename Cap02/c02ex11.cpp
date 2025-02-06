// c02ex11.cpp

#include <iostream>
#include <string> // Para manipulação de strings

int main(void) {
    std::string nome; // Declaração da variável para armazenar o nome

    std::cout << "Por favor, entre seu nome: ";
    std::getline(std::cin, nome); // Lê a linha completa, incluindo espaços

    std::cout << "Oi, " << nome << "! Seja bem-vindo!" << std::endl;

    std::cout << std::endl;
    std::cout << "Tecle <Enter> para encerrar... ";
    std::cin.get();

    return 0;
}
