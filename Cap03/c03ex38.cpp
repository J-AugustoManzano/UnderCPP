// c03ex38.cpp

#include <iostream>
#include <string>
#include <limits>
#include <print>

int main(void) {
    std::string nomes[5];
    std::string* ptrNomes = nomes;
    std::string x;

    // Trecho de entrada de dados
    std::println("Entrada de nomes:");
    std::println("");
    for (std::string *pi = ptrNomes; pi <= ptrNomes + 4; ++pi) {
        std::print("Nome {}: ", (pi - ptrNomes + 1));
        std::getline(std::cin, *pi);
    }

    // Trecho de processamento da classificação
    for (std::string* pi = ptrNomes; pi <= ptrNomes + 3; ++pi) {
        for (std::string* pj = pi + 1; pj <= ptrNomes + 4; ++pj) {
            if (*pi > *pj) {
                x = *pi;
                *pi = *pj;
                *pj = x;
            }
        }
    }

    // Trecho de saída com dados classificados
    std::println("");
    std::println("Nomes classificados:");
    std::println("");
    for (std::string* pi = ptrNomes; pi <= ptrNomes + 4; ++pi) {
        std::println("{}", *pi);
    }

    std::println("");
    std::print("Tecle <Enter> para encerrar... ");
    std::cin.get();

    return 0;
}
