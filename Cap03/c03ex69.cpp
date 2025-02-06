// c03ex69.cpp

#include <iostream>
#include <print>

// Definindo enumeração de forma mais segura (enum class)
enum class Meses : uint16_t
{
    janeiro = 1,
    fevereiro,
    marco,
    abril,
    maio,
    junho,
    julho,
    agosto,
    setembro,
    outubro,
    novembro,
    dezembro
};

int main(void)
{
    Meses mes;

    std::println("Teste de acesso a lista enumerada\n");

    mes = Meses::janeiro; // Definindo o mês como janeiro

    std::print("Mes definido = {} -> ", static_cast<uint16_t>(mes));
    std::print("em extenso equivale a ");

    // Usando switch para mostrar o nome do mês
    switch (mes)
    {
        case Meses::janeiro:   std::println("janeiro");   break;
        case Meses::fevereiro: std::println("fevereiro"); break;
        case Meses::marco:     std::println("marco");     break;
        case Meses::abril:     std::println("abril");     break;
        case Meses::maio:      std::println("maio");      break;
        case Meses::junho:     std::println("junho");     break;
        case Meses::julho:     std::println("julho");     break;
        case Meses::agosto:    std::println("agosto");    break;
        case Meses::setembro:  std::println("setembro");  break;
        case Meses::outubro:   std::println("outubro");   break;
        case Meses::novembro:  std::println("novembro");  break;
        case Meses::dezembro:  std::println("dezembro");  break;
    }

    std::println("");
    std::print("Tecle <Enter> para encerrar... ");
    std::cin.get();

    return 0;
}
