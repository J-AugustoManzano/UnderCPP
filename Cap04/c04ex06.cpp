// c04ex06.cpp

#include <iostream>
#include <print>
#include <string>
#include <cctype>
#include <limits>

int main(void) {
    char ch1;

    std::print("Entre um caractere: ");
    std::cin >> ch1;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::println("");

    if (std::isupper(ch1))
        std::println("Voce informou uma letra maisucula.");
    if (std::islower(ch1))
        std::println("Voce informou uma letra minuscula.");
    if (std::isdigit(ch1))
        std::println("Voce informou um digito (numeral).");
    if (std::ispunct(ch1))
        std::println("Voce informou um simbolo de pontuacao.");
    if (std::isalnum(ch1))
        std::print("Sua entrada: alfanumerica");
    if (std::isalpha(ch1))
        std::println(" = letra.");
    if (std::isdigit(ch1))
        std::println(" = numero.");
    if (std::ispunct(ch1))
        std::println("Sua entrada: um caractere de pontuacao.");
    if (std::iscntrl(ch1))
        std::println("Sua entrada: um caractere especial.");
    if (std::isprint(ch1))
        std::println("Este caractere e imprimivel.");
    std::println("");

    std::string texto = "Ola, Mundo 123!";
    std::println("Texto = {}", texto);
    std::println("");
    for (char ch2 : texto) {
        if (std::isalpha(ch2))
            std::println("{} = letra.", ch2);
        else if (std::isdigit(ch2))
            std::println("{} = digito.", ch2);
        else if (std::isspace(ch2))
            std::println("{} = espaco em branco.", ch2);
        else if (std::ispunct(ch2))
            std::println("{} = simbolo de pontuacao.", ch2);
    }

    std::println("");
    std::print("Tecle <Enter> para encerrar... ");
    std::cin.get();

    return 0;
}
