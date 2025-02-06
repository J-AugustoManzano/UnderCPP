// c04ex10.cpp

#include <iostream>
#include <locale>
#include <print>
#include <string>
#ifdef _WIN32
    #include <windows.h>
#endif

int main(void) {
    std::string nome;

    // Configura a localidade de acordo com o sistema operacional
    #ifdef _WIN32
        setlocale(LC_ALL, "Portuguese_Brazil.1252");
        SetConsoleCP(1252);
    #else
        setlocale(LC_ALL, "pt_BR.UTF-8");
    #endif

    std::cout << "Olá. Qual é o seu nome? ";
    std::getline(std::cin, nome);

    std::println("");
    std::cout << "Oi " << nome << " vamos estudar.";

    std::println("");
    std::print("Tecle <Enter> para encerrar... ");
    std::cin.get();

    return 0;
}
