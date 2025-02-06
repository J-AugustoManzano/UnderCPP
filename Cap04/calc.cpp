// calc.cpp

#include <cstdint>
#include "calc.hpp"

int64_t fatorial_base(int16_t n, int64_t acc) {
    if (n == 0 or n == 1) return acc;
    return fatorial_base(n - 1, n * acc);
}

int64_t fatorial(int16_t n) {
    return fatorial_base(n, 1);
}

int64_t somatorio_base(int16_t n, int64_t acc) {
    if (n == 0) return acc;
    return somatorio_base(n - 1, n + acc);
}

int64_t somatorio(int16_t n) {
    return somatorio_base(n, 0);
}
