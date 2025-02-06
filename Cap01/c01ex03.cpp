// c01ex03.cpp

#include <iostream>  // Para std::cerr, std::cout e std::endl
#include <cstdlib>   // Para std::atof
#include <stdexcept> // Para std::invalid_argument

int main(int argc, char* argv[]) {
    // Verifica se o número correto de argumentos foi passado
    if (argc != 4) {
        std::cerr << "Uso: " << argv[0] << " <valor1> <valor2> <operador>" << std::endl;
        return 1; // Retorna um código de erro
    }

    // Converte os argumentos de string para float
    double valor1 = std::atof(argv[1]);
    double valor2 = std::atof(argv[2]);
    char operador = argv[3][0]; // Define: operador é o primeiro caractere do terceiro argu-mento

    double resultado;

    // Realiza a operação com base no operador fornecido
    switch (operador) {
        case '+':
            resultado = valor1 + valor2;
            break;
        case '-':
            resultado = valor1 - valor2;
            break;
        case '*':
            resultado = valor1 * valor2;
            break;
        case '/':
            if (valor2 == 0) {
                std::cerr << "Erro: Divisao por zero!" << std::endl;
                return 1; // Retorna um código de erro
            }
            resultado = valor1 / valor2;
            break;
        default:
            std::cerr << "Erro: Operador invalido. Use +, -, * ou /." << std::endl;
            return 1; // Retorna um código de erro
    }

    // Exibe o resultado da operação
    std::cout << "Resultado: " << resultado << std::endl;

    std::cout << std::endl;
    std::cout << "Tecle <Enter> para encerrar... "; 
    std::cin.get();

    return 0; // Retorna 0 para indicar que o programa terminou com sucesso
}
