// c02ex67.cpp

#include <iostream>
#include <limits>
#include <print>

int16_t n;
int64_t fat;

void fatorial(void);

int main(void) {

    std::print("Entre um numero inteiro (0-20): ");
    std::cin >> n;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    fatorial();

    std::println("");
    std::print("Tecle <Enter> para encerrar... ");
    std::cin.get();

    return 0;
}

void fatorial(void) {
    fat = 1;
    for (int16_t i = 1; i <= n; ++i) {
        fat *= i;
    }
    std::println("Fatorial de {} equivale a: {}.", n, fat);
}
