#ifndef _VENTA_H
#define _VENTA_H

#include <iostream>
#include <sstream>

struct Fecha {
    short dia;
    short mes;
    int ano;

    std::string to_string() {
        std::stringstream stream;
        stream << dia << "/" << mes << "/" << ano;
        return stream.str();
    }
};

struct Venta {
    int cantidad;
    std::string descripcion;
    float precio_unidad;
    Fecha fecha;

    float precio_total();

    void generar_entrada_en_listado(std::stringstream& stream);
};

std::ostream& operator <<(std::stringstream& stream, const Fecha& fecha);

#endif
