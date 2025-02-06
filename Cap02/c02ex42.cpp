// c02ex42.cpp

#include <iostream>
#include <print>
#include <limits>

int main(void) {
    int16_t n, i, r;

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
    std::print("Tecle <Enter> para encerrar... ");
    std::cin.get();

    return 0;
}
