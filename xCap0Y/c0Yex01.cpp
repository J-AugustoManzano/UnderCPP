// c0Xex01.cpp

#include <iostream>
#include <print>
#include <sstream>
#include <thread>
#include <chrono>

int main(void) {
    // Limpa a tela
    std::print("\033[2J");

    // Define cores ANSI
    const std::string red_text = "\033[31m";
    const std::string green_text = "\033[32m";
    const std::string blue_text = "\033[34m";
    const std::string yellow_bg = "\033[43m";
    const std::string cyan_bg = "\033[46m";
    const std::string reset = "\033[0m";

    // Imprime uma mensagem inicial no topo
    std::ostringstream oss;
    oss << red_text << cyan_bg << "\033[1;1H" << "   Efeitos de Terminal ANSI em C++23!   "
        << reset;
    std::print("{}", oss.str());

    // Exemplo de texto colorido com fundo colorido em posições diferentes
    for (int i = 0; i <= 9; ++i) {
        int row = 3 + i;
        int col = 5 + i * 2;
        oss.str(""); // Limpa o conteúdo do ostringstream
        oss << blue_text << cyan_bg << "\033[" << row << ";" << col << "H" << "Linha Colorida "
            << i + 1 << reset;
        std::print("{}", oss.str());

        std::this_thread::sleep_for(std::chrono::milliseconds(200));
    }

    // Desenha uma borda simples
    for (int col = 1; col <= 40; ++col) {
        oss.str(""); // Limpa o conteúdo do ostringstream
        oss << blue_text << "\033[13;" << col << "H" << "-" << reset;
        std::print("{}", oss.str());
    }
    for (int row = 2; row <= 13; ++row) {
        oss.str(""); // Limpa o conteúdo do ostringstream
        oss << blue_text << "\033[" << row << ";1H" << "|" << reset;
        std::print("{}", oss.str());

        oss.str(""); // Limpa o conteúdo do ostringstream
        oss << blue_text << "\033[" << row << ";40H" << "|" << reset;
        std::print("{}", oss.str());
    }

    // Move o cursor para uma posição visível ao final e reseta o terminal
    oss.str(""); // Limpa o conteúdo do ostringstream
    oss << reset << "\033[15;1H";
    std::print("{}", oss.str());

    std::println("");
    std::print("Tecle <Enter> para encerrar... ");
    std::cin.get();

    return 0;
}
