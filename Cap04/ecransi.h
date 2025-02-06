// ecransi.h

/*
 Arquivo de cabeçalho para controle de vídeo
 em modo Terminal ANSI
*/

#ifndef ECRANSI_H
#define ECRANSI_H

#include <cstdint>

namespace ecra {

    // Enumerações para as cores de texto e fundo
    enum class Color {
        black    =  0, // Preto
        blue     =  4, // Azul
        green    =  2, // Verde
        cyan     =  6, // Ciano
        red      =  1, // Vermelho
        magenta  =  5, // Magenta
        brown    =  3, // Marrom
        lgray    =  7, // Cinza claro
        dgray    =  8, // Cinza escuro
        lblue    = 12, // Azul claro
        lgreen   = 10, // Verde claro
        lcyan    = 14, // Ciano claro
        lred     =  9, // Vermelho claro
        lmagenta = 13, // Magenta claro
        yellow   = 11, // Amarelo
        white    = 15  // Branco
    };

    void clrscr(void);
    void position(int16_t linha, int16_t coluna);
    void background(Color cor);
    void text(Color cor);
    void color(Color corFundo, Color corTexto);
    void normal(void);

} // namespace ecra

#endif // ECRANSI_H
