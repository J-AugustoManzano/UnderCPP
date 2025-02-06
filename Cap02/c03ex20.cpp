// c03ex20.cpp

#include <iostream>
#include <map>
#include <print>

int main(void) {
    std::map<int16_t, std::string, std::greater<>> meuMapa = {
        {1, "um"},
        {2, "dois"},
        {3, "tres"}
    };

    for (const std::pair<int16_t, std::string> &par : meuMapa) {
        std::println("{} -> {}", par.first, par.second);
    }

    std::println("");
    std::print("Tecle <Enter> para encerrar... ");
    std::cin.get();

    return 0;
}
