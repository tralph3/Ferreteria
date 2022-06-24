#include <fstream>
#include <iostream>
#include <vector>
#include "structs.h"
#include "utils.h"

Venta leer_una_venta(std::string linea) {
    std::vector<std::string> factura;
    split_string(linea, factura, '\t');

    Fecha* fecha = new Fecha;
    fecha->dia = string_to_int(factura[4]);
    fecha->mes = string_to_int(factura[5]);
    fecha->ano = string_to_int(factura[6]);

    Venta* venta = new Venta;
    venta->codigo = string_to_int(factura[0]);
    venta->cantidad = string_to_int(factura[1]);
    venta->descripcion = factura[2];
    venta->precio_unidad = string_to_float(factura[3]);
    venta->fecha = *fecha;

    return *venta;
}

std::vector<Venta> leer_ventas(std::string nombre) {
    std::vector<Venta> contenidos;
    std::string valor;
    char separador = '\t';

    std::ifstream archivo(nombre);
    while(getline(archivo, valor)) {
        Venta venta = leer_una_venta(valor);
        contenidos.push_back(venta);
    }

    return contenidos;
}

int main()
{
    const int MAX_REGS = 800;
    const int MAX_VENS = 100;

    Vendedor tito;
    tito.codigo = 123;
    std::vector<Venta> ventas = leer_ventas("VentasFerreteria.txt");
    ventas[0].print();
    std::cout << "\n\n";
    ventas[1].print();
    return 0;
}

