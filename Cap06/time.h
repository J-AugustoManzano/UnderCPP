// time.h

#ifndef TIME_H
#define TIME_H

#include <cstdint>
#include <string>

class Time {
private:
    uint16_t hour_;
    uint16_t minute_;
    uint16_t second_;
    bool is_time_valid_;

public:
    Time();
    Time(uint16_t hour, uint16_t minute, uint16_t second);

    // Converte a hora, minuto e segundo para segundos do dia
    uint32_t to_seconds(void) const noexcept;

    // Converte segundos do dia para hora, minuto e segundo
    static std::string from_seconds(uint32_t seconds);

    // Validação do tempo informado
    void validate_time();

    // Coloca e valida o novo tempo
    void set_time(uint16_t hour, uint16_t minute, uint16_t second);

    // Converte o tempo para o formato "HH:MM:SS"
    std::string to_string(void) const;

    // Verifica se o tempo é válido
    bool is_valid(void) const;
};

#endif // TIME_H
