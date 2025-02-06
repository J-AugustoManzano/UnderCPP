// c02ex49.cpp

#include <iostream>
#include <print>
#include <limits>

int main(void) {
    int16_t n, r;

    std::print("Entre o valor da tabuada: ");
    std::cin >> n;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::println("");

    for (int16_t i = 1; i <= 10; ++i) {
        r = n * i;
        std::println("{:>2} X {:>2} = {:>3}", n, i, r);
    }

    std::println("");
    std::print("Tecle <Enter> para encerrar... ");
    std::cin.get();

    return 0;
}
