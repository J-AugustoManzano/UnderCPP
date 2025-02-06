// c02ex19.cpp

#include <iostream>
#include <print>
#include <format> // Para formatar std::print e std::println

int main(void)
{

    std::println("Combinado .: {:*<+10.2f}, {:+#09X}", 3.14159, 10);
    std::println("Valores ...: {}, {}", 10'000., 100'000.);
    std::println("Valores ...: {}, {}", 10'000., std::format("{:.0f}", 100'000.));

    std::println("");
    std::print("Tecle <Enter> para encerrar... ");
    std::cin.get();

    return 0;
}
