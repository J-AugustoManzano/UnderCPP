// c05ex19.cpp

#include <iostream>
#include <print>
#include <string>
#include <vector>

class Capitulo {
public:
    int16_t numero;
    std::string conteudo;

    Capitulo(int16_t numero, const std::string& conteudo) : numero(numero), conteudo(conteudo) {}

    void exibirConteudo() const {
        std::println("Capitulo {}: {}", numero, conteudo);
    }
};

class Livro {
public:
    std::string titulo;
    std::vector<Capitulo> capitulos;

    Livro(const std::string& titulo) : titulo(titulo) {}

    void adicionarCapitulo(const Capitulo& capitulo) {
        capitulos.push_back(capitulo);
    }

    void exibirConteudo() const {
        std::println("Titulo: {}", titulo);
        std::println("");
        for (const Capitulo& capitulo : capitulos) {
            capitulo.exibirConteudo();
        }
    }
};

int main(void) {
    Livro livro("C++23: Underground Programmer");

    Capitulo capitulo1(1, "A linguagem C++");
    Capitulo capitulo2(2, "Programacao basica");
    Capitulo capitulo3(3, "Programacao intermediaria");
    Capitulo capitulo4(4, "Programacao complementar");
    Capitulo capitulo5(5, "Programacao com objetos");
    Capitulo capitulo6(6, "Programacao especializada");
    Capitulo capitulo7(7, "Programacao com fdata e hora");
    Capitulo capitulo8(8, "Programacao com arquivos");
    Capitulo capitulo9(9, "Apendices");

    livro.adicionarCapitulo(capitulo1);
    livro.adicionarCapitulo(capitulo2);
    livro.adicionarCapitulo(capitulo3);
    livro.adicionarCapitulo(capitulo4);
    livro.adicionarCapitulo(capitulo5);
    livro.adicionarCapitulo(capitulo6);
    livro.adicionarCapitulo(capitulo7);
    livro.adicionarCapitulo(capitulo8);
    livro.adicionarCapitulo(capitulo9);

    livro.exibirConteudo();

    std::println("");
    std::print("Tecle <Enter> para encerrar... ");
    std::cin.get();

    return 0;
}
