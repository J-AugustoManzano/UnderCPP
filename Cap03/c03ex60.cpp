// c03ex60.cpp

#include <iostream>
#include <cstdarg>
#include <print>

int64_t fatorial(int32_t valor, ...) {
    va_list args;
    va_start(args, valor);

    int64_t fator = 1;
    for (size_t i = 0; i < valor; ++i) {
        fator *= va_arg(args, int32_t);
    }
    va_end(args);

    return fator;
}

int main(void) {
    std::println("Fatorial de 5 (1, 2, 3, 4, 5) = {}", fatorial(5, 1, 2, 3, 4, 5));

    std::println("");
    std::print("Tecle <Enter> para encerrar... ");
    std::cin.get();

    return 0;
}
