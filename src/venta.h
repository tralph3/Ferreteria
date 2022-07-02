#ifndef _VENTA_H
#define _VENTA_H

#include <iostream>
#include <sstream>
#include "fecha.h"

struct Venta {
    int cantidad;
    std::string descripcion;
    float precio_unidad;
    Fecha fecha;

    float precio_total();

    void generar_entrada_en_listado(std::stringstream& stream);
};

#endif
