// c02ex43.cpp

#include <iostream>
#include <print>
#include <limits>
#include <cctype>

int main(void) {
    int16_t n, i, r;

    char continuar = 'S';  // cria e inicializa com 'S' para entrar no la�o
    do {
        std::print("Entre o valor da tabuada: ");
        std::cin >> n;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::println("");

        i = 1;
        do {
            r = n * i;
            std::println("{:>2} X {:>2} = {:>3}", n, i, r);
            ++i;
        } while (not (i > 10));

        std::println("");

        // Solicita ao usu�rio se quer continuar
        std::println("Deseja calcular outra tabuada?");
        std::print("Tecle \"S\" para sim - qualquer outra letra para nao): ");
        std::cin >> continuar;
        continuar = toupper(continuar);  // Converte para mai�scula
        std::println("");
    } while (not (continuar != 'S'));


    std::println("");
    std::print("Tecle <Enter> para encerrar... ");
    std::cin.get();

    return 0;
}
