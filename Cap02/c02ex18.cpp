// c02ex18.cpp

#include <iostream>
#include <print>

int main(void)
{

    std::println("Positico com sinal ....: {:+}", 10);
    std::println("Com espçao em brancio .: {: }", 10);

    std::println("");
    std::print("Tecle <Enter> para encerrar... ");
    std::cin.get();

    return 0;
}
