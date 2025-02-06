// c04ex14.cpp

#include <iostream>
#include <print>
#include <regex>
#include <string>

int main(void) {
    std::string texto = "Tenho 25 anos e possui 2 cachorros e 1 gato.";
    std::regex padrao(R"(\d+)"); // Expressão regular para capturar números inteiros

    std::sregex_iterator  numerosInicial =
        std::sregex_iterator(texto.begin(), texto.end(), padrao);
    std::sregex_iterator  numerosFinal = std::sregex_iterator();

    std::println("Numeros encontrados:");
    std::println("");
    for (std::sregex_iterator i = numerosInicial; i != numerosFinal; ++i) {
        std::smatch correspondencia = *i;
        std::println("{:>2}", correspondencia.str());
    }

    std::println("");
    std::print("Tecle <Enter> para encerrar... ");
    std::cin.get();

    return 0;
}
