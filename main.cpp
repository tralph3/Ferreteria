#include <algorithm>
#include <fstream>
#include <iostream>
#include <vector>
#include <bits/stdc++.h>
#include "utils.h"
#include "vendedor.h"
#include "venta.h"

void leer_y_registrar_venta(std::string linea, std::vector<Vendedor>& vendedores) {
    std::vector<std::string> factura;
    split_string(linea, factura, '\t');

    Fecha fecha;
    fecha.dia = string_to_int(factura[4]);
    fecha.mes = string_to_int(factura[5]);
    fecha.ano = string_to_int(factura[6]);

    int codigo_vendedor = string_to_int(factura[0]);
    int indice_vendedor = xxxxxxxx(codigo_vendedor, vendedores);

    Venta venta;
    venta.cantidad = string_to_int(factura[1]);
    venta.descripcion = factura[2];
    venta.precio_unidad = string_to_float(factura[3]);
    venta.fecha = fecha;

    vendedores[indice_vendedor].agregar_venta(venta);
}

void leer_ventas(std::vector<Vendedor>& vendedores, std::string nombre) {
    std::string linea;
    char separador = '\t';

    std::ifstream archivo(nombre);
    while(getline(archivo, linea)) {
        leer_y_registrar_venta(linea, vendedores);
    }
}

bool ordenar_por_codigo_vendedor(Vendedor vendedor1, Vendedor vendedor2) {
    return vendedor1.codigo > vendedor2.codigo;
}

float total_general(std::vector<Vendedor>& vendedores) {
    float total = 0;
    for (int i = 0; i < vendedores.size(); i++) {
        total += vendedores[i].total_ventas();
    }
    return total;
}

int codigo_vendedor_mayor_venta(std::vector<Vendedor>& vendedores) {
    float vendedor_mayor_venta[2] = {0, 0};

    for (int i = 0; i < vendedores.size(); i++) {
        float total_ventas = vendedores[i].total_ventas();
        if (total_ventas > vendedor_mayor_venta[0]) {
            vendedor_mayor_venta[0] = total_ventas;
            vendedor_mayor_venta[1] = vendedores[i].codigo;
        }
    }

    return vendedor_mayor_venta[1];
}

int main()
{
    const int MAX_REGS = 800;
    const int MAX_VENS = 100;

    std::vector<Vendedor> vendedores;
    leer_ventas(vendedores, "./VentasFerreteria.txt");

    std::sort(vendedores.begin(), vendedores.end(), ordenar_por_codigo_vendedor);

    for (int i = 0; i < vendedores.size(); i++) {
        std::cout << vendedores[i].generar_listado() << std::endl;
    }

    std::cout << std::setw(92) << std::left << "Total General:" << std::right << "$" << total_general(vendedores) << std::endl;
    std::cout << "Código del vendedor con mayor ventas: " << codigo_vendedor_mayor_venta(vendedores) << std::endl;

    return 0;
}

