// c0Xex10.cpp

#include <iostream>
#include <print>
#include <cstring>
#include <cctype>
#if defined _WIN32 || defined _WIN64
    #include <windows.h>
#else
    #include <termios.h>
    #include <unistd.h>
    #include <cstdio>
#endif

#if defined _WIN32 || defined _WIN64
    char getpwd(void) {
        char caractere;
        HANDLE teclado;
        DWORD escrita = 0, numCarac;
        teclado = GetStdHandle(STD_INPUT_HANDLE);
        GetConsoleMode(teclado, &escrita);
        SetConsoleMode(teclado, escrita & ~(ENABLE_LINE_INPUT | ENABLE_ECHO_INPUT));
        ReadConsole(teclado, &caractere, 1, &numCarac, NULL);
        SetConsoleMode(teclado, escrita);
        return caractere;
    }
#else
    int16_t getpwd(void) {
        int16_t caractere;
        termios leitura;
        termios teclado;
        tcgetattr(STDIN_FILENO, &leitura);
        teclado = leitura;
        leitura.c_lflag &= ~(ICANON | ECHO);
        tcsetattr(STDIN_FILENO, TCSANOW, &leitura);
        caractere = getchar();
        tcsetattr(STDIN_FILENO, TCSANOW, &teclado);
        return caractere;
    }
#endif

std::string readpwd(void) {
    std::string senha;
    char caractere;
    #if defined _WIN32 || defined _WIN64
        char cr = (char)13;
        char bs = (char)8;
    #else
        char cr = '\n';
        char bs = (char)127;
    #endif
    do {
        caractere = getpwd();
        if (isprint(caractere)) {
            std::print("*");
            senha += caractere;
        } else if (caractere == bs and not senha.empty()) {
            std::print("\b \b");
            senha.pop_back();
        }
    } while (caractere != cr);
    return senha;
}

int main(void) {
    std::string cadLogin, cadSenha, entLogin, entSenha;
    int16_t tentativas = 3;

    std::println("CADASTRO DE ACESSO PARA USUARIO");
    std::println("");
    std::print("Entre nome para login ....: ");
    std::getline(std::cin, cadLogin);

    std::print("Entre senha para login ...: ");
    cadSenha = readpwd();

    std::print("\n\n");
    std::println("Usuario e senha cadastrados.");
    std::print("\n");

    std::print("Tecle <Enter> para encerrar... ");
    std::cin.get();
    std::print("\n");

    do {
        std::print("");
        std::print("Entre nome do usuario ....: ");
        std::getline(std::cin, entLogin);

        if (cadLogin != entLogin) {
            std::println("");
            std::println("ERRO: nome invalido.");
            std::println("");
            continue; // Não decrementar tentativas
        }

        std::print("Entre senha do usuario ...: ");
        entSenha = readpwd();

        std::println("\n");

        if (cadSenha != entSenha) {
            --tentativas;
            if (tentativas > 0) {
                std::print("ERRO: senha ionvalida - voce possui {}", tentativas);
                std::println("{}", tentativas > 1 ? " tentativas." : " tentativa.");
                std::println("");
            }
        } else {
            std::println("ACESSO BEM SUCEDIDO");
            break;
        }
    } while (tentativas > 0);

    if (tentativas == 0) {
        std::println("ACESSO NEGADO");
    }

    std::println("");
    std::print("Tecle <Enter> para encerrar... ");
    std::cin.get();

    return 0;
}
