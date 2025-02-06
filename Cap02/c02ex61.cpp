// c02ex61.cpp

#include <iostream>
#include <print>

int main(void) {
    int16_t idade;

    do {
        std::print("Entre uma idade (0-120): ");
        std::cin >> idade;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    } while (idade < 0 or idade > 120);

    std::println("");
    std::println("idade = {:>3}", idade);

    std::println("");
    std::print("Tecle <Enter> para encerrar... ");
    std::cin.get();

    return 0;
}
