// c04ex12.cpp

#include <iostream>
#include <print>
#include <regex>
#include <string>

int main(void) {
    // Texto de exemplo contendo vários números de telefone em diferentes formatos
    std::string texto =
        "Contatos: (11) 91234-5678, 11-91234-5678, +55 11 91234 5678, (21)98765-4321";

    // Expressão regular para capturar números de telefone
    std::regex regex_telefone(R"((\+?\d{1,3})?\s*\(?\d{2}\)?[\s-]?\d{4,5}[- ]?\d{4})");

    // Iterador para encontrar todas as correspondências
    std::sregex_iterator telefonesInicial =
        std::sregex_iterator(texto.begin(), texto.end(), regex_telefone);
    std::sregex_iterator telefonesFinal = std::sregex_iterator();

    // Verifica se encontrou algum número de telefone e imprime os resultados
    if (telefonesInicial != telefonesFinal) {
        std::println("Numeros de telefone encontrados:");
        std::println("");
        for (std::sregex_iterator i = telefonesInicial; i != telefonesFinal; ++i) {
            std::smatch correspondencia = *i;
            std::cout << correspondencia.str() << '\n';
        }
    } else {
        std::cout << "Nenhum numero de telefone encontrado.\n";
    }

    std::println("");
    std::print("Tecle <Enter> para encerrar... ");
    std::cin.get();

    return 0;
}
