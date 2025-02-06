// c03ex05.cpp

#include <iostream>
#include <print>
#include <vector>

int main(void) {
    // Definindo a matriz tridimensional:
    // 7 dias, 4 períodos por dia, 2 regiões da cidade
    int16_t dias = 7;
    int16_t regioes = 2;
    int16_t periodos = 4; // Manhã, Tarde, Noite, Madrugada (Madrg)

    std::vector<std::vector<std::vector<float>>>
        temps(dias, std::vector<std::vector<float>>(regioes, std::vector<float>(periodos)));

    // Preenchendo a matriz com temps aleatórias
    for (int16_t dia = 0; dia < dias; ++dia) {
        for (int16_t regiao = 0; regiao < regioes; ++regiao) {
            for (int16_t periodo = 0; periodo < periodos; ++periodo) {
                // temperaturas variando entre 20 e 35 graus
                temps[dia][regiao][periodo] = (20 + (rand() % 15));
            }
        }
    }

    std::println("Temperaturas semanal por regioes:\n");
    std::println("Dia\tRegiao\t\tManha\tTarde\tNoite\tMadrg");
    std::println("-----------------------------------------------------");

    // Exibindo as temps para cada dia, região e período
    for (int16_t dia = 0; dia < dias; ++dia) {
        for (int16_t regiao = 0; regiao < regioes; ++regiao) {
            std::print("Dia {}\tRegiao {}", dia + 1, regiao + 1);
            for (int16_t periodo = 0; periodo < periodos; ++periodo) {
                std::print("\t{:>5.2f}", temps[dia][regiao][periodo]);
            }
            std::println("");
        }
        std::println("-----------------------------------------------------");
    }

    std::println("");
    std::print("Tecle <Enter> para encerrar... ");
    std::cin.get();

    return 0;
}
