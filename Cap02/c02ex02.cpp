// c02ex02.cpp

#include <iostream>
#include <iomanip> // Para definir a precisão das casas decimais

int main(void) {
    // Definindo dois valores numéricos de ponto flutuante
    float num1 = 10.5f;
    float num2 = 3.2f;

    // Operações Aritméticas
    float soma = num1 + num2;
    float subtracao = num1 - num2;
    float multiplicacao = num1 * num2;
    int16_t divInteira = static_cast<int16_t>(num1 / num2);
    float divReal = num1 / num2;
    int16_t resto = static_cast<int16_t>(num1) % static_cast<int16_t>(num2);

    // Definir precisão com duas casas decimais
    std::cout << std::fixed << std::setprecision(2);

    // Exibir os resultados
    std::cout << "Soma .........................: " << std::setw(5) << soma << std::endl;
    std::cout << "Subtracao ....................: " << std::setw(5) << subtracao << std::endl;
    std::cout << "Multiplicacao ................: " << std::setw(5) << multiplicacao << std::endl;
    std::cout << "Divisao (quociente inteiro) ..: " << std::setw(5) << divInteira << std::endl;
    std::cout << "Divisao (quociente real) .....: " << std::setw(5) << divReal << std::endl;
    std::cout << "Resto da divisao .............: " << std::setw(5) << resto << std::endl;

    std::cout << std::endl;
    std::cout << "Tecle <Enter> para encerrar... ";
    std::cin.get();

    return 0;
}
