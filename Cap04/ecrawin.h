// ecrawin.h

/*
 Arquivo de cabeçalho para controle de vídeo
 em modo WinAPI
*/

#ifndef ECRANSI_H
#define ECRANSI_H

#include <cstdint>

namespace ecra {

    // Enumerações para as cores de texto e fundo, adaptadas à WinAPI
    enum class Color {
        black    =  0, // Preto
        blue     =  1, // Azul
        green    =  2, // Verde
        cyan     =  3, // Ciano
        red      =  4, // Vermelho
        magenta  =  5, // Magenta
        brown    =  6, // Marrom
        lgray    =  7, // Cinza claro
        dgray    =  8, // Cinza escuro
        lblue    =  9, // Azul claro
        lgreen   = 10, // Verde claro
        lcyan    = 11, // Ciano claro
        lred     = 12, // Vermelho claro
        lmagenta = 13, // Magenta claro
        yellow   = 14, // Amarelo
        white    = 15  // Branco
    };

    // Declarações das funções
    void clrscr(void);
    void position(int16_t linha, int16_t coluna);
    void background(Color cor);
    void text(Color cor);
    void color(Color corFundo, Color corTexto);
    void normal(void);

} // namespace ecra

#endif // ECRANSI_H
