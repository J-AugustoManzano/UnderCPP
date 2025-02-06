// c02ex12.cpp

#include <iostream>
#include <print>
#include <chrono>   // Para obter o tempo do sistema de forma moderna

int main(void)
{
    std::string nome = "Bjarne Stroustrup";
    int16_t ano_nascimento = 1950;

    // Obtém o ano atual
    auto agora = std::chrono::system_clock::now();
    auto tempo = std::chrono::year_month_day{std::chrono::floor<std::chrono::days>(agora)};
    int16_t ano_atual = static_cast<int>(tempo.year());

    // Calcula a idade
    uint16_t idade = ano_atual - ano_nascimento;

    // Exibe a idade e a mensagem de encerramento
    std::print("{} possui aproximadamente {} anos.\n", nome, idade);

    std::println("");
    std::print("Tecle <Enter> para encerrar... ");
    std::cin.get();

    return 0;
}
