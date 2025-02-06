// c02ex34.cpp

#include <iostream>
#include <print>
#include <limits>

int main(void) {
    int16_t mes;

    std::print("Entre um numero equivalente a um MES: ");
    std::cin >> mes;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::println("");

    if (mes == 1) {
        std::println("Janeiro");
        goto fim;
    } else if (mes == 2) {
        std::println("Fevereiro");
        goto fim;
    } else if (mes == 3) {
        std::println("Marco");
        goto fim;
    } else if (mes == 4) {
        std::println("Abril");
        goto fim;
    } else if (mes == 5) {
        std::println("Maio");
        goto fim;
    } else if (mes == 6) {
        std::println("Junho");
        goto fim;
    } else if (mes == 7) {
        std::println("Julho");
        goto fim;
    } else if (mes == 8) {
        std::println("Agosto");
        goto fim;
    } else if (mes == 9) {
        std::println("Setembro");
        goto fim;
    } else if (mes == 10) {
        std::println("Outubro");
        goto fim;
    } else if (mes == 11) {
        std::println("Novembro");
        goto fim;
    } else if (mes == 12) {
        std::println("Dezembro");
        goto fim;
    } else {
        std::println("Mes invalido");
    }

    fim:

    std::println("");
    std::print("Tecle <Enter> para encerrar... ");
    std::cin.get();

    return 0;
}
