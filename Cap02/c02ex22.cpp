// c02ex22.cpp

#include <iostream>
#include <limits>
#include <print>

using std::cin;
using std::numeric_limits;
using std::streamsize;
using std::print;
using std::println;

int main(void) {
    int32_t valor1, valor2;

    print("Entre o primeiro valor inteiro ..: ");
    cin >> valor1;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    print("Entre o segundo valor inteiro ...: ");
    cin >> valor2;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    println("A soma dos valores equivale a: {}", (valor1 + valor2));

    println("");
    print("Tecle <Enter> para encerrar... ");
    cin.get();

    return 0;
}

