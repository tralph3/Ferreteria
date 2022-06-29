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

    std::string generar_listado_1();

    std::string generar_listado_2();

    std::string generar_listado_3();

    float total_ventas();

    int cantidad_total();
};

int xxxxxxxx(int id, std::vector<Vendedor>& vendedores);

void leer_y_registrar_venta(std::string linea, std::vector<Vendedor>& vendedores);

void leer_ventas(std::vector<Vendedor>& vendedores, const char* nombre);

bool ordenar_vendedores_por_codigo(Vendedor vendedor1, Vendedor vendedor2);

bool ordenar_vendedores_por_cantidad_articulos(Vendedor vendedor1, Vendedor vendedor2);

bool ordenar_vendedores_por_total_ventas(Vendedor vendedor1, Vendedor vendedor2);

float total_general(std::vector<Vendedor>& vendedores);

int codigo_vendedor_mayor_venta(std::vector<Vendedor>& vendedores);

#endif
