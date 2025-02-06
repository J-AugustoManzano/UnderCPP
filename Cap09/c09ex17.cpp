// c09ex17.cpp

#include <iostream>
#include <string>
#include <print>
#include <fstream>

using namespace std;

void pausa(void) {
    std::println("");
    std::print("Tecle <Enter> para encerrar... ");
    std::cin.get();
}

int main(void) {
    string mensagem;
    uint64_t tamanho;
    char* numeroCaracteres;
    fstream arqbin("arqbin6.dat ", ios::app | ios::binary);
    if (not arqbin) {
        cerr << "Erro ao abrir o arquivo." << endl;
         pausa();
        return 1;
    }

    std::print("Informe uma mensagem --> ");
    getline(cin, mensagem);

    tamanho = mensagem.size();
    numeroCaracteres = reinterpret_cast<char*>(&tamanho);

    // Escreve o tamanho da mensagem (uint64_t) no arquivo
    arqbin.write(numeroCaracteres, sizeof(tamanho));

    // Escreve os caracteres da mensagem no arquivo
    arqbin.write(mensagem.c_str(), tamanho);

    arqbin.close();

    pausa();
    return 0;
}
