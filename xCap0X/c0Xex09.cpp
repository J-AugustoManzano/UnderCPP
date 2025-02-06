/ c0Xex09.cpp

#include <iostream>
#include <print>
#include <string>
#if defined _WIN32 || defined _WIN64
    #include <windows.h>
#else
    #include <termios.h>
    #include <unistd.h>
#endif

int main(void)
{
    #if defined _WIN64 || defined _WIN32
        HANDLE teclado;
        DWORD leitura = 0;
        teclado = GetStdHandle(STD_INPUT_HANDLE);
        GetConsoleMode(teclado, &leitura);
        SetConsoleMode(teclado, leitura & (~ENABLE_ECHO_INPUT));
    #else
        termios teclado_sem_eco;
        termios teclado_com_eco;
        tcgetattr(STDIN_FILENO, &teclado_sem_eco);
        teclado_com_eco = teclado_sem_eco;
        teclado_com_eco.c_lflag &= ~(ICANON | ECHO);
        tcsetattr(STDIN_FILENO, TCSANOW, &teclado_com_eco);
    #endif

    std::string palavra1, palavra2;

    std::print("Entre palavra 1 (sem eco): ");
    std::getline(std::cin, palavra1);
    std::println("");

    #if defined _WIN64 || defined _WIN32
        SetConsoleMode(teclado, leitura);
    #else
        tcsetattr(STDIN_FILENO, TCSANOW, &teclado_sem_eco);
    #endif

    std::print("Entre palavra 2 (com eco): ");
    std::getline(std::cin, palavra2);
    std::println("");

    std::println("Palavra 1: {}", palavra1);
    std::println("Palavra 2: {}", palavra2);

    std::println("");
    std::print("Tecle <Enter> para encerrar... ");
    std::cin.get();

    return 0;
}
