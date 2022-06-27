#ifndef _VENDEDOR_H
#define _VENDEDOR_H

#include <iostream>
#include <iomanip>
#include <vector>
#include "venta.h"
#include "utils.h"

struct Vendedor {
    int codigo;
    std::vector<Venta> ventas;

    void agregar_venta(Venta venta);

    std::string generar_listado();

    float total_ventas();
};

int xxxxxxxx(int id, std::vector<Vendedor>& vendedores);

#endif
