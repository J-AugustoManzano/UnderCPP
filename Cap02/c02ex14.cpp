// c02ex14.cpp

#include <iostream>
#include <print>

int main(void)
{
    double valor = 3.14159;

    std::println("Valor com 2 casas decimais ..: {:.2f}", valor);
    std::println("Valor em notacao cientifica .: {:e}", valor);

    std::println("");
    std::print("Tecle <Enter> para encerrar... ");
    std::cin.get();

    return 0;
}
