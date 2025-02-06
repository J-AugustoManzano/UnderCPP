// ecrawin.cpp

#include <windows.h> // Inclui a WinAPI
#include <cstdint>
#include <print>
#include "ecransi.h"

namespace ecra {

    // Fun��o para obter as dimens�es do terminal
    void getTerminalSize(int16_t &linhas, int16_t &colunas) {
        HANDLE tela = GetStdHandle(STD_OUTPUT_HANDLE);
        CONSOLE_SCREEN_BUFFER_INFO telaInfo;

        // Obt�m as informa��es do buffer de tela
        if (GetConsoleScreenBufferInfo(tela, &telaInfo)) {
            // N�mero de linhas vis�veis
            linhas = telaInfo.srWindow.Bottom - telaInfo.srWindow.Top + 1;
            // N�mero de colunas vis�veis
            colunas = telaInfo.srWindow.Right - telaInfo.srWindow.Left + 1;
        } else {
            // Em caso de erro, define um valor padr�o
            linhas = 24;   // 24 linhas (padr�o de terminais antigos)
            colunas = 80;  // 80 colunas (padr�o de terminais antigos)
        }
    }

    // Limpa a tela
    void clrscr(void) {
        HANDLE tela = GetStdHandle(STD_OUTPUT_HANDLE);
        CONSOLE_SCREEN_BUFFER_INFO telaInfo;
        DWORD totalPosicoes, atualizado;
        COORD posicoes;

        int16_t linhas, colunas;
        // Obt�m as dimens�es do terminal
        getTerminalSize(linhas, colunas);

        // Calcula o n�mero total de posi��es vis�veis
        totalPosicoes = linhas * colunas;

        posicoes.X = 0;
        posicoes.Y = 0;

        // Preenche a tela com espa�os
        FillConsoleOutputCharacter(tela, (TCHAR) ' ', totalPosicoes, posicoes, &atualizado);

        // Posiciona o cursor no in�cio
        SetConsoleCursorPosition(tela, posicoes);

    }

    // Posiciona o cursor na tela
    void position(int16_t linha, int16_t coluna) {
        int16_t linhas, maxColunas;

        // Obt�m as dimens�es do console
        getTerminalSize(linhas, maxColunas);

        // Limita o posicionamento para estar dentro dos limites do console
        if (coluna >= 1 and coluna <= maxColunas and linha >= 1 and linha <= linhas) {
            HANDLE tela = GetStdHandle(STD_OUTPUT_HANDLE);
            COORD posicoes;
            posicoes.X = static_cast<SHORT>(coluna - 1); // Ajusta para 0-index
            posicoes.Y = static_cast<SHORT>(linha - 1);  // Ajusta para 0-index

            // Posiciona o cursor nas coordenadas fornecidas
            SetConsoleCursorPosition(tela, posicoes);
        } else {
            std::print("Posicao fora dos limites do terminal.");
        }
    }

    // Altera cor do fundo da tela
    void background(Color corFundo) {
        HANDLE tela = GetStdHandle(STD_OUTPUT_HANDLE);
        CONSOLE_SCREEN_BUFFER_INFO telaInfo;

        // Obt�m as informa��es atuais do buffer de tela
        if (GetConsoleScreenBufferInfo(tela, &telaInfo)) {
            // Mant�m a cor do texto
            int16_t corTexto = telaInfo.wAttributes % 16; // Obt�m a cor do texto

            // Define a nova cor de fundo
            int16_t cor = static_cast<int16_t>(corFundo) + corTexto;

            SetConsoleTextAttribute(tela, cor);
        }
    }

    // Altera cor da frente da tela
    void text(Color corTexto) {
        HANDLE tela = GetStdHandle(STD_OUTPUT_HANDLE);
        CONSOLE_SCREEN_BUFFER_INFO telaInfo;

        // Obt�m as informa��es atuais do buffer de tela
        if (GetConsoleScreenBufferInfo(tela, &telaInfo)) {
            // Mant�m a cor de fundo
            int16_t corFundo = telaInfo.wAttributes / 16 * 16;

            // Define a nova cor de texto
            SetConsoleTextAttribute(tela, corFundo + static_cast<int16_t>(corTexto));
        }
    }

    // Define cor de fundo e frente para uma linha de texto
    void color(Color corFundo, Color corTexto) {
        HANDLE tela = GetStdHandle(STD_OUTPUT_HANDLE);

        // Calcula o valor combinado de cor sem opera��es bitwise
        int16_t corFundoInt = static_cast<int16_t>(corFundo);
        int16_t corTextoInt = static_cast<int16_t>(corTexto);

        // Define a nova cor, onde a cor do fundo est� em um n�vel mais alto
        int16_t corCombinada = (corFundoInt * 16) + corTextoInt;
        SetConsoleTextAttribute(tela, corCombinada);
    }

    // Volta tela para modo padr�o
    void normal(void) {
        HANDLE tela = GetStdHandle(STD_OUTPUT_HANDLE);
        // Define cor padr�o do console (branco sobre preto)
        SetConsoleTextAttribute(tela, 7); // Fundo cinza claro, texto preto
    }

} // namespace ecra
