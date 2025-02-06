// c05ex22.cpp

#include <iostream>
#include <print>
#include <string>
#include <vector>
#include <memory>
#include <algorithm>
#include <iomanip>
#include <limits>

// Classe base para disciplinas
struct Disciplina {
protected:
    double nota;
public:
    explicit Disciplina(double nota = 0.0) : nota(nota) {}
    virtual ~Disciplina() = default;

    virtual double pegaNota() const { return nota; }
    virtual void poeNota(double n) { nota = n; }
};

// Herança para disciplinas específicas
class Matematica : public Disciplina { public: using Disciplina::Disciplina; };
class Portugues : public Disciplina { public: using Disciplina::Disciplina; };
class Informatica : public Disciplina { public: using Disciplina::Disciplina; };

// Classe Aluno com herança múltipla
class Aluno : public Matematica, public Portugues, public Informatica {
private:
    static size_t contadorMatricula; // Contador estático para gerar matrículas únicas
    size_t matricula;
    std::string nome;

public:
    Aluno(const std::string& nome, double notaMat, double notaPort, double notaInfo)
        : nome(nome), matricula(++contadorMatricula) {
        Matematica::poeNota(notaMat);
        Portugues::poeNota(notaPort);
        Informatica::poeNota(notaInfo);
    }

    ~Aluno() { std::println("Aluno {} destruido.", nome); }

    // Função para calcular a média das notas
    double calcularMedia(void) const {
        return (Matematica::pegaNota() + Portugues::pegaNota() + Informatica::pegaNota()) / 3.0;
    }

    // Métodos para obter informações
    size_t pegaMatricula(void) const { return matricula; }
    const std::string& pegaNome() const { return nome; }

    void exibirInformacoesTabular(void) const {
        // Limitar o nome para 20 caracteres na exibição
        std::string nomeExibicao = nome.length() > 20 ? nome.substr(0, 20) : nome;
        double media = calcularMedia();
        std::string situacao = media >= 5.0 ? "Aprovado" : "Reprovado";

        std::println("{:9} {:<20} {:11.1f} {:11.1f} {:11.1f} {:11.1f} {:<11}",
                     matricula, nomeExibicao, Matematica::pegaNota(), Portugues::pegaNota(),
                     Informatica::pegaNota(), media, situacao);
    }

    // Exibição em formato de ficha
    void exibirInformacoesFicha(void) const {
        double media = calcularMedia();
        std::string situacao = media >= 5.0 ? "Aprovado" : "Reprovado";

        std::println("Ficha do Aluno");
        std::println("");
        std::println("Matricula .........................: {:04}", matricula);
        std::println("Nome ..............................: {}", nome);
        std::println("Matematica ........................: {:4.1f}", Matematica::pegaNota());
        std::println("Portugues .........................: {:4.1f}", Portugues::pegaNota());
        std::println("Informatica .......................: {:4.1f}", Informatica::pegaNota());
        std::println("Media .............................: {:4.1f}", media);
        std::println("Situacao ..........................: {}", situacao);
        std::println("");
    }

    // Função estática para obter o próximo número de matrícula
    static size_t pegaProximaMatricula(void) {
        return contadorMatricula + 1;
    }
};

size_t Aluno::contadorMatricula = 0;

// Classe Escola que contém um arranjo dinâmico de alunos
class Escola {
private:
    std::vector<std::unique_ptr<Aluno>> alunos;

public:
    // Função para adicionar aluno e exibir matrícula automaticamente
    void adicionarAluno(void) {
        int matriculaGerada = Aluno::pegaProximaMatricula();

        std::println("");
        std::println("Matricula .........................: {:04}", matriculaGerada);

        std::string nome;
        double notaMat, notaPort, notaInfo;

        std::print("Entre o nome do aluno .............: ");
        std::getline(std::cin, nome);
        do {
            std::print("Entre a nota de Matematica ........: ");
            std::cin >> notaMat;
        } while (notaMat < 0.0 or notaMat > 10.0);
        do {
            std::print("Entre a nota de Lingua Portuguesa .: ");
            std::cin >> notaPort;
        } while (notaPort < 0.0 or notaPort > 10.0);
        do {
            std::print("Entre a nota de Informatica .......: ");
            std::cin >> notaInfo;
        } while (notaInfo < 0.0 or notaInfo > 10.0);
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        std::unique_ptr<Aluno> aluno = std::make_unique<Aluno>(nome, notaMat, notaPort, notaInfo);
        alunos.push_back(std::move(aluno));

        std::println("");
        std::println("Aluno cadastrado com sucesso!");
        std::println("");
    }

    void exibirCabecalho(void) const {
        std::println("");
        std::println("{:<9} {:<20} {:>11} {:>11} {:>11} {:>11} {:<11}",
            "Matricula", "Nome", "Matematica", "Portugues", "Informatica", "Media", "Situacao");
        std::println("{:-<88}", "");
    }

    void exibirTodosAlunos(void) const {
        exibirCabecalho();
        for (const std::unique_ptr<Aluno>& aluno : alunos) {
            aluno->exibirInformacoesTabular();
        }
        std::println("");
    }

    void ordenarPorNome(void) {
        std::sort(alunos.begin(), alunos.end(),
            [](const std::unique_ptr<Aluno>& a, const std::unique_ptr<Aluno>& b) {
            return a->pegaNome() < b->pegaNome();
        });
    }

    void ordenarPorMatricula(void) {
        std::sort(alunos.begin(), alunos.end(),
            [](const std::unique_ptr<Aluno>& a, const std::unique_ptr<Aluno>& b) {
            return a->pegaMatricula() < b->pegaMatricula();
        });
    }

    void ordenarPorMedia(void) {
        std::sort(alunos.begin(), alunos.end(),
            [](const std::unique_ptr<Aluno>& a, const std::unique_ptr<Aluno>& b) {
            return a->calcularMedia() > b->calcularMedia(); // Maior média primeiro
        });
    }

    // Função para pesquisar aluno por nome ou matrícula
    void pesquisarAluno(void) {
        std::println("");
        std::println("Pesquisar por: ");
        std::println("");
        std::println("[1] - Nome");
        std::println("[2] - Matricula");
        std::println("[3] - Voltar");
        std::println("");
        std::print("Escolha uma opcao: ");

        int16_t opcao;
        std::cin >> opcao;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        if (opcao == 1) {
            std::string nomePesquisa;

            std::println("");
            std::print("Entre o nome: ");
            std::getline(std::cin, nomePesquisa);
            std::println("");

            bool encontrado = false;
            for (std::unique_ptr<Aluno>& aluno : alunos) {
                if (aluno->pegaNome() == nomePesquisa) {
                    aluno->exibirInformacoesFicha();
                    encontrado = true;
                    break;
                }
            }
            if (not encontrado) {
                std::println("Aluno nao encontrado.");
                std::println("");
            }
        } else if (opcao == 2) {
            size_t matriculaPesquisa;
            std::println("");
            std::print("Entre a matricula: ");
            std::cin >> matriculaPesquisa;
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::println("");

            bool encontrado = false;
            for (std::unique_ptr<Aluno>& aluno : alunos) {
                if (aluno->pegaMatricula() == matriculaPesquisa) {
                    aluno->exibirInformacoesFicha();
                    encontrado = true;
                    break;
                }
            }
            if (not encontrado) {
                std::println("Aluno nao encontrado.");
                std::println("");
            }
        } else if (opcao == 3) {
            // Retornar ao menu principal
            return;
        } else {
            std::println("");
            std::println("Opcao invalida.");
            std::println("");
        }
    }
};

// Função para exibir o menu e capturar a escolha do usuário
void exibirMenu(void) {
    std::println("--- MENU: CADASTRO ESCOLAR ---");
    std::println("");
    std::println("[1] - Cadastrar aluno");
    std::println("[2] - Exibir alunos por nome");
    std::println("[3] - Exibir alunos por matricula");
    std::println("[4] - Exibir alunos por media");
    std::println("[5] - Pesquisar aluno");
    std::println("[6] - Sair");
    std::println("");
    std::print("Escolha uma opcao: ");
}

int main(void) {
    Escola escola;
    bool rodando = true;

    do {
        exibirMenu();

        int opcao;
        std::cin >> opcao;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        switch (opcao) {
            case 1:
                escola.adicionarAluno();
                break;
            case 2:
                escola.ordenarPorNome();
                escola.exibirTodosAlunos();
                break;
            case 3:
                escola.ordenarPorMatricula();
                escola.exibirTodosAlunos();
                break;
            case 4:
                escola.ordenarPorMedia();
                escola.exibirTodosAlunos();
                break;
            case 5:
                escola.pesquisarAluno();
                break;
            case 6:
                rodando = false;
                std::println("Saindo do programa...");
                break;
            default:
                std::println("Opcao invalida.");
        }
    } while (rodando);

    return 0;
}
