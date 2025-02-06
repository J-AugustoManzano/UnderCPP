// date.h

#ifndef DATE_H
#define DATE_H

#include <cstdint>
#include <string>

enum class Month {
    January = 1,
    February,
    March,
    April,
    May,
    June,
    July,
    August,
    September,
    October,
    November,
    December
};

class Date {
private:
    uint16_t day_;
    uint16_t month_;
    uint16_t year_;
    bool is_date_valid_;

public:
    Date();
    Date(uint16_t day, uint16_t month, uint16_t year);

    // Verifica se ano é bissexto
    bool is_leap_year(void) const noexcept;

    // Pega o último dia do mês
    uint16_t last_day_of_month(void) const noexcept;

    // Validação da data informada
    void validate_date();

    // Coloca e valida a nova data
    void set_date(uint16_t day, uint16_t month, uint16_t year);

    // Converte a data para o formato "DD/MM/AAAA"
    std::string to_string(void) const;

    // Converte uma data para o dia juliano
    static uint64_t date_to_jd(uint16_t day, uint16_t month, uint16_t year);

    // Converte um dia juliano para uma data no formato "DD/MM/AAAA"
    static std::string jd_to_date(uint64_t julianDay);

    // Converte do formato "DD/MM/AAAA" para "AAAAMMDD"
    static uint64_t date_ansi(const std::string& dt);

    // Retorna dia da semana
    static uint8_t day_of_week(const std::string& dt);

    // Verifica se a data é válida
    bool is_valid(void) const;

    // Valida data da páscoa entre 01/01/0001 até 31/12/9999
    static std::string calculate_easter(uint16_t year);

};

#endif // DATE_H

