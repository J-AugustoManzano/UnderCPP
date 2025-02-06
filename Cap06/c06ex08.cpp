#include <iostream>
#include <print>
#include <sstream>
#include <limits>
#include <chrono>
#include "date.h"

int main(void) {
    std::string entra_data, nova_data;
    char delimitador;
    uint16_t dia, mes, ano;

    std::println("OPERACAOES COM DATA");
    std::println("-------------------\n");

    std::print("Entre data no formato DD/MM/AAAA ...: ");
    std::cin >> entra_data;
    std::stringstream ss(entra_data);
    ss >> dia >> delimitador >> mes >> delimitador >> ano;
    std::println("");

    Date date(dia, mes, ano);

    if (not date.is_valid()) {
        std::println("Data invalida!");
    } else {
        // Teste de ano bissexto
        std::println("Ano bissexto .......................: {}",
                     (date.is_leap_year() ? "Sim" : "Nao"));

        // Teste do último dia do mês
        std::println("Ultimo dia do mes ..................: {}", date.last_day_of_month());

        // Teste de conversão para dia juliano
        uint64_t dia_juliano = Date::date_to_jd(dia, mes, ano);
        std::println("Dia juliano ........................: {}", dia_juliano);

        // Teste de conversão de dia juliano para data
        std::string dj_para_data = Date::jd_to_date(dia_juliano);
        std::println("Data a partir do dia juliano .......: {}", dj_para_data);

        // Teste de conversão para formato ANSI
        uint64_t data_ansi = Date::date_ansi(entra_data);
        std::println("Data no formato ANSI ...............: {}", data_ansi);

        // Teste de dia da semana
        uint8_t dia_da_semana = Date::day_of_week(entra_data);
        std::println("Dia da semana - numero .............: {}",
                     static_cast<uint16_t>(dia_da_semana));

        // Calcular e exibir a data da Páscoa
        std::string pascoa = Date::calculate_easter(ano);
        std::println("Pascoa em seu nascimento ...........: {}", pascoa);

        // Converter a data da Páscoa para dia juliano
        dia = std::stoi(pascoa.substr(0, 2));
        mes = std::stoi(pascoa.substr(3, 2));
        ano = std::stoi(pascoa.substr(6, 4));
        uint64_t dia_juliano_pascoa = Date::date_to_jd(dia, mes, ano);

        // Calcular e exibir a data do Carnaval (47 dias antes da Páscoa)
        uint64_t dia_juliano_carnaval = dia_juliano_pascoa - 47;
        std::string carnaval = Date::jd_to_date(dia_juliano_carnaval);
        std::println("Carnaval em seu nascimento .........: {}", carnaval);

        // Calcular e exibir a data do Corpus Christi (60 dias após a Páscoa)
        uint64_t dia_juliano_corpus_christi = dia_juliano_pascoa + 60;
        std::string corpus_christi = Date::jd_to_date(dia_juliano_corpus_christi);
        std::println("Corpus Christi em seu nascimento ...: {}", corpus_christi);

        // Solicitar um número inteiro para somar e subtrair da data
        uint16_t dias;
        std::println("");
        std::print("Entre um valor inteiro .............: ");
        std::cin >> dias;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        // Somar dias
        std::println("");
        uint64_t novo_dj_adicionado = dia_juliano + dias;
        nova_data = Date::jd_to_date(novo_dj_adicionado);
        std::println("Nova data apos adicionar {:>3} dias ..: {}", dias, nova_data);
        std::println("Dia juliano da nova data ...........: {}", novo_dj_adicionado);
        std::println("Dia da semana da nova data .........: {}",
                     static_cast<uint16_t>(Date::day_of_week(nova_data)));

        // Subtrair dias
        std::println("");
        uint64_t novo_dj_subtraido = dia_juliano - dias;
        nova_data = Date::jd_to_date(novo_dj_subtraido);
        std::println("Nova data apos subtrair {:>3} dias ...: {}", dias, nova_data);
        std::println("Dia juliano da nova data ...........: {}", novo_dj_subtraido);
        std::println("Dia da semana da nova data .........: {}",
                     static_cast<uint16_t>(Date::day_of_week(nova_data)));
    }

    std::println("");
    std::print("Tecle <Enter> para encerrar... ");
    std::cin.get();

    return 0;
}
