// c03ex59.cpp

#include <iostream>
#include <print>
#include <type_traits>

template <typename... Args>
std::common_type_t<Args...> somatorio(Args... args) {
    return (args + ...);
}

int main(void) {
    std::println("Somatorio de 1, 2, 3, 4, 5: {:>3}", somatorio(1, 2, 3, 4, 5));
    std::println("Somatorio de 1.4, 2.5, 3.2: {:>3.1f}", somatorio(1.4, 2.5, 3.2));

    std::println("");
    std::print("Tecle <Enter> para encerrar... ");
    std::cin.get();

    return 0;
}
