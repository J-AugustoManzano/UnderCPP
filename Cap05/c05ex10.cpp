// c05ex10.cpp

#include <iostream>
#include <print>
#include <string>

class Pessoa
{
protected:
    std::string nome;

public:
    Pessoa(const std::string& nomePessoa)
        : nome(nomePessoa) {}

    virtual ~Pessoa() {}

    void mostrarNome() const
    {
        std::println("{}", nome);
    }

    virtual void mostrarProfissao() const
    {
        std::println("Atividade profissional desconhecida.");
    }
};

class Medico : public Pessoa
{
public:
    Medico(const std::string& nomePessoa) : Pessoa(nomePessoa) {}
    virtual ~Medico() {}

    void mostrarProfissao() const override
    {
        std::println("Voce possui formacao em medicina.");
    }
};

class Advogado : public Pessoa
{
public:
    Advogado(const std::string& nomePessoa) : Pessoa(nomePessoa) {}
    virtual ~Advogado() {}

    void mostrarProfissao() const override
    {
        std::println("Voce possui formacao em advocacia.");
    }
};

int main(void)
{
    Pessoa* profissional;

    Advogado advogado("Marisa Monteiro");
    Medico medico("Carlos de Andrade");
    Pessoa pessoa("Joana Silva");

    profissional = &advogado;
    profissional->mostrarNome();
    profissional->mostrarProfissao();
    std::println("");

    profissional = &medico;
    profissional->mostrarNome();
    profissional->mostrarProfissao();
    std::println("");

    profissional = &pessoa;
    profissional->mostrarNome();
    profissional->mostrarProfissao();

    std::println("");
    std::print("Tecle <Enter> para encerrar... ");
    std::cin.get();

    return 0;
}
