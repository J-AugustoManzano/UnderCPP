// c03ex33.cpp

#include <iostream>
#include <print>

int main(void) {
    int16_t a, *ptrA = &a;

    std::println("Endereco atual ...............: {:p}", static_cast<void*>(ptrA));

    ptrA += 10;
    std::println("Proximo endereco a frente ....: {:p}", static_cast<void*>(ptrA));

    ptrA += 10;
    std::println("Proximo endereco a frente ....: {:p}", static_cast<void*>(ptrA));

    ptrA -= 10;
    std::println("Endereco anterior para tras ..: {:p}", static_cast<void*>(ptrA));

    ptrA -= 10;
    std::println("Endereco anterior para tras ..: {:p}", static_cast<void*>(ptrA));

    std::println("");
    std::print("Tecle <Enter> para encerrar... ");
    std::cin.get();

    return 0;
}
