// date.cpp

#include <iostream>
#include <iomanip>
#include <sstream>
#include <cctype>
#include "date.h"

// Construtor padrão
Date::Date() : day_(0), month_(0), year_(0), is_date_valid_(false) {}

// Construtor parametrizado
Date::Date(uint16_t day, uint16_t month, uint16_t year)
    : day_(day), month_(month), year_(year), is_date_valid_(false) {
    validate_date();
}

// Verifica se ano é bissexto
bool Date::is_leap_year(void) const noexcept {
    if (year_ < 1582) {
        return year_ % 4 == 0;
    } else {
        return (year_ % 400 == 0) or (year_ % 4 == 0 and year_ % 100 != 0);
    }
}

// Pega o último dia do mês
uint16_t Date::last_day_of_month(void) const noexcept {
    if (month_ == static_cast<uint16_t>(Month::February)) {
        return is_leap_year() ? 29 : 28;
    }
    if (month_ <= static_cast<uint16_t>(Month::July)) {
        return (month_ % 2 != 0) ? 31 : 30;
    }
    return (month_ % 2 != 0) ? 30 : 31;
}

// Validação da data informada
void Date::validate_date(void) {
    is_date_valid_ = (year_  >= 1     and year_  <= 9999) and
                     (month_ >= 1     and month_ <= 12) and
                     (day_   >= 1     and day_   <= last_day_of_month()) and not
                     ((year_ == 1582) and
                     (month_ == 10)   and
                     (day_   >= 5     and day_ <= 14));
}

// Coloca e valida a nova data
void Date::set_date(uint16_t day, uint16_t month, uint16_t year) {
    day_ = day;
    month_ = month;
    year_ = year;
    validate_date();
}

// Converte a data para o formato "DD/MM/YYYY"
std::string Date::to_string(void) const {
    if (is_date_valid_) {
        std::ostringstream oss;
        oss << std::setfill('0') << std::setw(2) << day_ << '/'
            << std::setw(2) << month_ << '/' << std::setw(4) << year_;
        return oss.str();
    }
    return "**/**/****";
}

// Converte uma data para o dia juliano
uint64_t Date::date_to_jd(uint16_t day, uint16_t month, uint16_t year) {
    if (month < 3) {
        year -= 1;
        month += 12;
    }

    uint64_t A, B, C, D, E, F;
    if (year > 1582 or (year == 1582 and (month > 10 or (month == 10 and day >= 15)))) {
        // Calendário Gregoriano
        A = year / 100;
        B = A / 4;
        C = 2 - A + B;
    } else {
        // Calendário Juliano
        C = 0;
    }

    D = static_cast<uint64_t>(365.25 * (year + 4716));
    E = static_cast<uint64_t>(30.6001 * (month + 1));
    F = D + E + day + C - 1524;

    return F;
}

// Converte um dia juliano para uma data no formato "DD/MM/YYYY"
std::string Date::jd_to_date(uint64_t julianDay) {
    uint64_t A = julianDay;
    uint64_t B, C, D, E, F, G, H, I, J, K;

    if (A > 2299160) {
        B = static_cast<uint64_t>((A - 1867216.25) / 36524.25);
        C = A + 1 + B - B / 4;
    } else {
        C = A;
    }

    D = C + 1524;
    E = static_cast<uint64_t>((D - 122.1) / 365.25);
    F = static_cast<uint64_t>(E * 365.25);
    G = static_cast<uint64_t>((D - F) / 30.6001);
    H = D - F - static_cast<uint64_t>(G * 30.6001);

    if (G < 14) {
        I = G - 1;
    } else {
        I = G - 13;
    }

    if (I > 2) {
        J = E - 4716;
    } else {
        J = E - 4715;
    }

    if (J > 0) {
        K = J;
    } else {
        K = J + 1;
    }

    std::ostringstream oss;
    oss << std::setw(2) << std::setfill('0') << H << "/"
        << std::setw(2) << std::setfill('0') << I << "/"
        << std::setw(4) << std::setfill('0') << K;

    return oss.str();
}

// Converte do formato "DD/MM/AAAA" para "AAAAMMDD"
uint64_t Date::date_ansi(const std::string& dt) {
    std::string date;
    date.reserve(8);

    // Retira os caracteres não numéricos
    for (char caractere : dt) {
        if (std::isdigit(caractere)) {
            date.push_back(caractere);
        }
    }

    // Monta o formato AAAAMMDD
    date = date.substr(4, 4) + date.substr(2, 2) + date.substr(0, 2);

    return std::stoull(date);  // Retorna a data no formato numérico inteiro longo
}

// Retorna dia da semana
uint8_t Date::day_of_week(const std::string& dt) {
    uint16_t day, month, year;
    std::stringstream ss(dt);
    char delimiter;
    ss >> day >> delimiter >> month >> delimiter >> year;

    uint64_t julianDay = date_to_jd(day, month, year);
    return static_cast<uint8_t>((julianDay + 1) % 7);
}

// Verifica se a data é válida
bool Date::is_valid(void) const {
    return is_date_valid_;
}

std::string Date::calculate_easter(uint16_t year) {
    uint16_t a, b, c, d, e, f, g, h, i, j, k, l, m, n, p;

    if (year >= 1583) {  // Calendário Gregoriano desde 1583
        a = year % 19;
        b = year / 100;
        c = year % 100;
        d = b / 4;
        e = b % 4;
        f = (b + 8) / 25;
        g = (b - f + 1) / 3;
        h = (19 * a + b - d - g + 15) % 30;
        i = c / 4;
        k = c % 4;
        l = (32 + 2 * e + 2 * i - h - k) % 7;
        m = (a + 11 * h + 22 * l) / 451;
        n = (h + l - 7 * m + 114) / 31;  // Mês
        p = (h + l - 7 * m + 114) % 31 + 1;  // Dia
    } else {  // Calendário Juliano, antes de 1583
        a = year % 4;
        b = year % 7;
        c = year % 19;
        d = (19 * c + 15) % 30;
        e = (2 * a + 4 * b - d + 34) % 7;
        n = (d + e + 114) / 31;  // Mês
        p = (d + e + 114) % 31 + 1;  // Dia
    }

    std::ostringstream date;
    date << std::setfill('0') << std::setw(2) << p << "/"
         << std::setfill('0') << std::setw(2) << n << "/"
         << year;

    return date.str();
}
