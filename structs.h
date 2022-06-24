#ifndef _STRUCTS_H
#define _STRUCTS_H

#include <cstdio>
#include <iostream>
#include <sstream>
#include <vector>

struct Fecha {
    short dia;
    short mes;
    int ano;

    void print() {
        printf("%d/%d/%d", dia, mes, ano);
    }
};

struct Venta {
    int codigo;
    int cantidad;
    std::string descripcion;
    float precio_unidad;
    Fecha fecha;

    void print() {
        std::cout << "Código: " << codigo << std::endl;
        std::cout << "Cantidad: " << cantidad << std::endl;
        std::cout << "Descripcion: " << descripcion << std::endl;
        std::cout << "Precio por unidad: " << precio_unidad<< std::endl;
        std::cout << "Fecha: ";
        fecha.print();
    }

    int precio_total() {
        return cantidad * precio_unidad;
    }
};

struct Vendedor {
    int codigo;
    std::vector<Venta> ventas;

    void agregarVenta(Venta venta) {
        ventas.push_back(venta);
    }

    std::string generar_listado() {
        std::ostringstream cabecera;

        return "";
    }

    void print() {
        std::cout << "Código: " << codigo << std::endl;
        for(int i = 0; i < ventas.size(); i++) {
            ventas[i].print();
        }
    }

    int total_ventas() {
        int total = 0;
        for(int i = 0; i < ventas.size(); i++) {
            total += ventas[i].precio_total();
        }

        return total;
    }
};
#endif
