#include <iostream>
#include <sstream>
#include <vector>
#include <bits/stdc++.h>
#include "utils.h"
#include "vendedor.h"
#include "venta.h"

void generar_cabecera_listado_2(std::stringstream& stream) {
    stream << std::setw(25) << std::left << "Código de Vendedor";
    stream << std::setw(20) << std::left << "Cantidad Total";
    stream << std::endl;
}

void generar_cabecera_listado_3(std::stringstream& stream) {
    stream << std::setw(25) << std::left << "Código de Vendedor";
    stream << std::setw(20) << std::left << "Importe Total";
    stream << std::endl;
}

void lista_1(std::vector<Vendedor>& vendedores) {
    std::sort(
        vendedores.begin(), vendedores.end(), ordenar_vendedores_por_codigo
    );

    for (size_t i = 0; i < vendedores.size(); i++) {
        std::cout << vendedores[i].generar_listado_1() << std::endl;
    }

    std::cout << std::setw(92) << std::left << "Total General:" << std::right << "$" << total_general(vendedores) << std::endl;
    std::cout << "Código del vendedor con mayor ventas: " << codigo_vendedor_mayor_venta(vendedores) << std::endl;

}

void lista_2(std::vector<Vendedor>& vendedores) {
    std::stringstream stream;
    generar_cabecera_listado_2(stream);
    std::cout << stream.str();

    std::sort(
        vendedores.begin(), vendedores.end(), ordenar_vendedores_por_cantidad_articulos
    );

    for (size_t i = 0; i < vendedores.size(); i++) {
        std::cout << vendedores[i].generar_listado_2() << std::endl;
    }
}

void lista_3(std::vector<Vendedor>& vendedores) {
    std::stringstream stream;
    generar_cabecera_listado_3(stream);
    std::cout << stream.str();

    std::sort(
        vendedores.begin(), vendedores.end(), ordenar_vendedores_por_total_ventas
    );

    for (size_t i = 0; i < vendedores.size(); i++) {
        std::cout << vendedores[i].generar_listado_3() << std::endl;
    }
}


int main()
{
    std::vector<Vendedor> vendedores;
    leer_ventas(vendedores, "./VentasFerreteria.txt");

    lista_1(vendedores);
    std::cout << std::endl;
    std::cout << std::endl;
    lista_2(vendedores);
    std::cout << std::endl;
    std::cout << std::endl;
    lista_3(vendedores);

    return 0;
}

