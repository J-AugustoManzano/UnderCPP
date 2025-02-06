// c04ex17.cpp
// Plataforma cruzada

#include <iostream>
#include <print>

#ifdef _WIN32
    #include <windows.h>
#elif __linux__
    #include <unistd.h>
#else
    #error "Sistema operacional nao suportado!"
#endif

void clrscr(void) {
    #ifdef _WIN32
        HANDLE tela = GetStdHandle(STD_OUTPUT_HANDLE);
        CONSOLE_SCREEN_BUFFER_INFO telaInfo;
        DWORD totalPosicoes, atualizado;
        COORD posicoes;
        posicoes.X = 0;
        posicoes.Y = 0;
        FillConsoleOutputCharacter(tela, (TCHAR) ' ', totalPosicoes, posicoes, &atualizado);
        SetConsoleCursorPosition(tela, posicoes);
    #elif __linux__
        std::print("\033[2J\033[1;1H");
    #else
        std::println("Sistema operacional não suportado.");
    #endif
}

int main(void) {
    clrscr();
    #ifdef _WIN32
        std::println("A tela foi limpa no Windows.");
    #elif __linux__
        std::println(""A tela foi limpa no Linux.");
    #endif

    std::print("\n");
    std::print("Tecle <Enter> para encerrar... ");
    std::cin.get();

    return 0;
}
