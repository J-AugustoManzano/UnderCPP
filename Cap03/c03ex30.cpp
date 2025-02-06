// c03ex30.cpp

#include <iostream>
#include <string>
#include <print>

int main(void) {
    char        chr, *ptrChr = nullptr;
    int16_t     i16, *ptrI16 = nullptr;
    int32_t     i32, *ptrI32 = nullptr;
    int64_t     i64, *ptrI64 = nullptr;
    short       sht, *ptrSht = nullptr;
    float       flt, *ptrFlt = nullptr;
    double      dbl, *ptrDbl = nullptr;
    long double ldb, *ptrLdb = nullptr;
    bool        bul, *ptrBul = nullptr;
    std::string str, *ptrStr = nullptr;

    std::println("Tamanho 'char' ..........: {:>2} bytes", sizeof(chr));
    std::println("Tamanho 'int16_t' .......: {:>2} bytes", sizeof(i16));
    std::println("Tamanho 'int32_t' .......: {:>2} bytes", sizeof(i32));
    std::println("Tamanho 'int64_t' .......: {:>2} bytes", sizeof(i64));
    std::println("Tamanho 'short' .........: {:>2} bytes", sizeof(sht));
    std::println("Tamanho 'float' .........: {:>2} bytes", sizeof(flt));
    std::println("Tamanho 'double' ........: {:>2} bytes", sizeof(dbl));
    std::println("Tamanho 'long double' ...: {:>2} bytes", sizeof(ldb));
    std::println("Tamanho 'bool' ..........: {:>2} bytes", sizeof(bul));
    std::println("Tamanho 'string' ........: {:>2} bytes", sizeof(str));

    std::println("");
    std::println("Tamanho 'p char' ........: {:>2} bytes", sizeof(ptrChr));
    std::println("Tamanho 'p int16_t' .....: {:>2} bytes", sizeof(ptrI16));
    std::println("Tamanho 'p int32_t' .....: {:>2} bytes", sizeof(ptrI32));
    std::println("Tamanho 'p int64_t' .....: {:>2} bytes", sizeof(ptrI64));
    std::println("Tamanho 'p short' .......: {:>2} bytes", sizeof(ptrSht));
    std::println("Tamanho 'p float' .......: {:>2} bytes", sizeof(ptrFlt));
    std::println("Tamanho 'p double' ......: {:>2} bytes", sizeof(ptrDbl));
    std::println("Tamanho 'p long double' .: {:>2} bytes", sizeof(ptrLdb));
    std::println("Tamanho 'p bool' ........: {:>2} bytes", sizeof(ptrBul));
    std::println("Tamanho 'p string' ......: {:>2} bytes", sizeof(ptrStr));

    std::println("");
    std::print("Tecle <Enter> para encerrar... ");
    std::cin.get();

    return 0;
}
