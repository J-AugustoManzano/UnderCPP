// ecransi.cpp

/*
 C�digo de implementa��o da biblioteca "ecransi.cpp".
 Arquivo com c�digo das funcionalidades do cabe�alho "ecransi.h"
*/

#include <iostream>
#include <print>
#include <cstdint>
#include <sys/ioctl.h>
#include <unistd.h>
#include "ecransi.h"

namespace ecra {

    // Fun��o para obter as dimens�es do terminal
    void getTerminalSize(int16_t &linhas, int16_t &colunas) {
        winsize w;
        if (ioctl(STDOUT_FILENO, TIOCGWINSZ, &w) == -1) {
            // Em caso de erro, define um valor padr�o
            linhas = 24;   // 24 linhas (padr�o de terminais antigos)
            colunas = 80;  // 80 colunas (padr�o de terminais antigos)
        } else {
            // Obt�m as dimens�es reais do terminal
            linhas = w.ws_row;
            colunas = w.ws_col;
        }
    }

    // Limpa a tela
    void clrscr(void) {
        std::print("\033[2J\033[1;1H");
    }

    // Posiciona o cursor na tela
    void position(int16_t linha, int16_t coluna) {
        int16_t maxLinhas, maxColunas;
        getTerminalSize(maxLinhas, maxColunas);  // Obt�m as dimens�es do terminal

        // Limita o posicionamento para estar dentro dos limites do terminal
        if (coluna >= 1 and coluna <= maxColunas and linha >= 1 and linha <= maxLinhas) {
            std::print("\033[{};{}H", linha, coluna);
        } else {
            std::print("Posicao fora dos limites do terminal.");
        }
    }

    // Altera cor do fundo da tela
    void background(Color corFundo) {
        std::print("\033[48;5;{}m", static_cast<int16_t>(corFundo));
    }

    // Altera cor da frente da tela
    void text(Color corTexto) {
        std::print("\033[38;5;{}m", static_cast<int16_t>(corTexto));
    }

    // Define cor de fundo e frente para uma linha de texto
    void color(Color corFundo, Color corTexto) {
        background(corFundo);
        text(corTexto);
    }

    // Volta tela para modo padr�o
    void normal(void) {
        std::print("\033[0m");
    }

} // namespace ecra
