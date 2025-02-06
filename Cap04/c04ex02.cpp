// c04ex02.cpp

#include <iostream>
#include <print>
#include <string>

int main(void) {
    std::string mensagem1 = "A";
    std::string mensagem2 = "1234";
    std::string mensagem3 = "Linguagem C++";

    std::println("Mensagem 1: {}", mensagem1);
    std::println("Mensagem 2: {}", mensagem2);
    std::println("Mensagem 3: {}", mensagem3);

    std::println("");
    std::print("Tecle <Enter> para encerrar... ");
    std::cin.get();

    return 0;
}
