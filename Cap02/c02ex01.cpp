// c02ex01.cpp

#include <iostream>
#include <iomanip>   // para std::setprecision
#include <limits>    // para std::numeric_limits
#include <numbers>   // para as constantes matemáticas

int main(void) {
    // Configurar precisão máxima de ponto flutuante para exibição
    std::cout << std::setprecision(std::numeric_limits<double>::max_digits10) << std::fixed;

    std::cout << "Constantes da biblioteca std::numbers:" << std::endl;
    std::cout << std::endl;

    std::cout << "e ...........: " << std::numbers::e << std::endl;
    std::cout << "log2e .......: " << std::numbers::log2e << std::endl;
    std::cout << "log10e ......: " << std::numbers::log10e << std::endl;
    std::cout << "pi ..........: " << std::numbers::pi << std::endl;
    std::cout << "inv_pi ......: " << std::numbers::inv_pi << std::endl;
    std::cout << "inv_sqrtpi ..: " << std::numbers::inv_sqrtpi << std::endl;
    std::cout << "ln2 .........: " << std::numbers::ln2 << std::endl;
    std::cout << "ln10 ........: " << std::numbers::ln10 << std::endl;
    std::cout << "sqrt2 .......: " << std::numbers::sqrt2 << std::endl;
    std::cout << "sqrt3 .......: " << std::numbers::sqrt3 << std::endl;
    std::cout << "inv_sqrt3 ...: " << std::numbers::inv_sqrt3 << std::endl;
    std::cout << "egamma ......: " << std::numbers::egamma << std::endl;
    std::cout << "phi .........: " << std::numbers::phi << std::endl;

    std::cout << std::endl;
    std::cout << "Tecle <Enter> para encerrar... ";
    std::cin.get();

    return 0;
}

