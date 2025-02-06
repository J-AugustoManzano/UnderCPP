// c08ex20.cpp

#include <iostream>
#include <print>
#include <vector>
#include <numeric>

int main(void) {
    // Horas registradas diariamente
    std::vector<double> horasTrabalhadas = {8.5, 7.0, 8.0, 9.0, 6.5, 3.0, 1.5};

    // Calculando o total de horas trabalhadas
    double totalHoras = std::accumulate(horasTrabalhadas.begin(), horasTrabalhadas.end(), 0.0);

    std::println("Total de horas trabalhadas na semana: {} horas.", totalHoras);

    // Verifica se houve hora extra (acima de 40 horas por semana)
    if (totalHoras > 40.0) {
        std::println("Horas extras realizadas: {} horas.", totalHoras - 40.0);
    } else {
        std::println("Nenhuma hora extra realizada.");
    }

    std::println("");
    std::print("Tecle <Enter> para encerrar... ");
    std::cin.get();

    return 0;
}
