// c0Xex06.cpp

#include <iostream>
#include <print>
#include <string>

std::string xorEncryptDecrypt(const std::string &texto, char chave)
{
    std::string resultado = texto;
    for (char &c : resultado) {
        c ^= chave; // XOR com a chave: c = c ^ chave
    }
    return resultado;
}

int main(void) {
    std::string messagem = "Hello, World!";
    char chave = 'K'; // Chave simples

    // Cifra a mensagem
    std::string encript = xorEncryptDecrypt(messagem, chave);
    std::println("Mensagem cifrada ....: {}", encript);

    // Decifra a mensagem
    std::string decript = xorEncryptDecrypt(encript, chave);
    std::println("Mensagem decifrada ..: {}", decript);

    std::println("");
    std::print("Tecle <Enter> para encerrar... ");
    std::cin.get();

    return 0;
}
