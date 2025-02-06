// c03ex65.cpp

#include <iostream>
#include <print>

int main(void) {
    auto soma = [](int32_t a, int32_t b) -> int64_t {
        return a + b;
    };

    std::println("Soma de 5 e 3 = {}", soma(5, 3));

    std::println("");
    std::print("Tecle <Enter> para encerrar... ");
    std::cin.get();

    return 0;
}
