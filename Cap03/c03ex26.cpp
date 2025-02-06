// c03ex26.cpp

#include <iostream>
#include <print>
#include <map>
#include <string>
#include <limits>

int main(void) {
    std::map<std::string, int16_t> idades = {
        {"Ana", 25},
        {"Bruno", 30},
        {"Carlos", 28},
        {"Diana", 22}
    };
    std::string nome;

    std::println("Valores no mapa:");
    std::println("");
    for (const auto& par : idades) {
        std::println("{}: {} anos", par.first, par.second);
    }

    std::println("");
    std::cout << "Entre nome para pesquisar: ";
    std::getline(std::cin, nome);

    std::map<std::string, int16_t>::iterator it = idades.find(nome);

    std::println("");
    if (it != idades.end()) {
        std::println("{} tem {} anos.", (*it).first, (*it).second);
    } else {
        std::println("Nome {} nao encontrado no mapa.", nome);
    }

    std::println("");
    std::print("Tecle <Enter> para encerrar... ");
    std::cin.get();

    return 0;
}
