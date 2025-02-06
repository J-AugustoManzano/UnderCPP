// c04ex05.cpp

#include <iostream>
#include <print>
#include <string>
#include <vector>
#include <limits>

int main(void) {
    std::vector<std::string> pronomes = {"eu", "tu", "ele", "nos", "vos", "eles"};
    std::vector<std::string> sufixos = {"o", "as", "a", "amos", "ais", "am"};
    std::string verbo, raiz;

    std::println("==============================================");
    std::println("CONJULGACAO DE VERBO REGULAR TERMINADO EM 'AR'");
    std::println("TEMPO: PRESENTE DO INDICATIVO");
    std::println("==============================================");
    std::println("");

    std::print("Entre um verbo: ");
    std::cin >> verbo;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::println("");

    // Verificar se o verbo é válido e chamar a conjugação correta
    raiz = verbo.substr(0, verbo.size() - 2);
    if (verbo.size() > 2) {
        for (size_t i = 0; i < pronomes.size(); ++i) {
            std::println("{} {}{}", pronomes[i], raiz, sufixos[i]);
        }
    } else {
        std::println("Erro: entrada invalida.");
    }

    std::println("");
    std::print("Tecle <Enter> para encerrar... ");
    std::cin.get();

    return 0;
}
