// c04ex11.cpp

#include <iostream>
#include <print>
#include <regex>
#include <string>

int main(void) {
    // Texto de exemplo contendo vários e-mails
    std::string texto =
        "Contatos: maria.silva@example.com, joao123@gmail.com, email-invalido@, tes-te@site.org";

    // Expressão regular para capturar e-mails
    std::regex regex_email(R"(\b[A-Za-z0-9._%+-]+@[A-Za-z0-9.-]+\.[A-Za-z]{2,}\b)");

    // Iterador para encontrar todas as correspondências
    std::sregex_iterator e_mailInicial =
        std::sregex_iterator(texto.begin(), texto.end(), regex_email);
    std::sregex_iterator e_mailFinal = std::sregex_iterator();

    // Verifica se encontrou algum e-mail e imprime os resultados
    if (e_mailInicial != e_mailFinal) {
        std::println("E-mails validos encontrados:");
        std::println("");
        for (std::sregex_iterator i = e_mailInicial; i != e_mailFinal; ++i) {
            std::smatch correspondencia = *i;
            std::println("{}", correspondencia.str());
        }
    } else {
        std::println("Nenhum e-mail encontrado.");
    }

    std::println("");
    std::print("Tecle <Enter> para encerrar... ");
    std::cin.get();

    return 0;
}
