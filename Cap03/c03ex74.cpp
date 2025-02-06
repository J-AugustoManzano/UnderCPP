// c03ex74.cpp

#include <iostream>
#include <print>

#define PRODUTO1(X, Y) ((X) * (Y))
#define PRODUTO2(X, Y) (X * Y)

int main(void)
{

    std::println("(2 + 3) x 4 = {} - resultado correto", PRODUTO1(2 + 3, 4));
    std::println("(2 + 3) x 4 = {} - resultado incorreto", PRODUTO2(2 + 3, 4));

    std::println("");
    std::print("Tecle <Enter> para encerrar... ");
    std::cin.get();

    return 0;
}
