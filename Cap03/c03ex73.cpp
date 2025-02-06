// c03ex73.cpp

#include <iostream>
#include <print>
#include <limits>

#define TROCA(a, b)    \
    do {               \
        auto x = (a);  \
        (a) = (b);     \
        (b) = x;       \
    } while (0)

int main(void)
{

    int16_t a, b;

    std::print("Entre o valor [A]: ");
    std::cin >> a;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::print("Entre o valor [B]: ");
    std::cin >> b;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    TROCA(a, b);

    std::println("");
    std::println("Agora [A] possui o valor {}", a);
    std::println("Agora [B] possui o valor {}", b);

    std::println("");
    std::print("Tecle <Enter> para encerrar... ");
    std::cin.get();

    return 0;
}
