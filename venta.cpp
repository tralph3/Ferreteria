#include <iostream>
#include <ostream>
#include <iomanip>
#include "venta.h"

std::ostream& operator <<(std::ostream& stream, const Fecha& fecha) {
    stream << fecha.dia << "/" << fecha.mes << "/" << fecha.ano;
    return stream;
}

float Venta::precio_total() {
    return cantidad * precio_unidad;
}

void Venta::generar_entrada_en_listado(std::stringstream& stream) {
    stream << std::setw(12) << std::left << fecha.to_string();
    stream << std::setw(10) << std::left << cantidad;
    stream << std::setw(25) << std::left << descripcion;
    stream << std::setw(20) << std::left << precio_unidad;
    stream << "$" << std::setw(15) << std::left << precio_total();
}
