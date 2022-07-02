#include "fecha.h"

std::string Fecha::to_string() {
    std::stringstream stream;
    stream << dia << "/" << mes << "/" << ano;
    return stream.str();
}
