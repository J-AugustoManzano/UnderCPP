// c01ex01.cpp

#include <iostream> // Inclusão da biblioteca padrão de entrada e saída

// Função principal: ponto de entrada do programa
int main() {
    // Comando para imprimir uma mensagem na tela
    std::cout << "Ola, Mundo!" << std::endl; // std::endl adiciona uma nova linha e limpa o buffer

    std::cout << std::endl;
    std::cout << "Tecle <Enter> para encerrar... "; // Antes de encerrar pede <Enter>
    std::cin.get();

    return 0; // Indica que o programa terminou com sucesso
}
