#include "vendedor.h"
#include <fstream>

void Vendedor::agregar_venta(Venta venta) {
    ventas.push_back(venta);
}

std::string Vendedor::generar_listado_1() {
    std::stringstream listado;

    listado << "Código de Vendedor: " << codigo << std::endl;
    generar_cabecera(listado);
    for (int i = 0; i < ventas.size(); i++) {
        listado << std::setw(10) << std::left << i + 1;
        ventas[i].generar_entrada_en_listado(listado);
        listado << std::endl;
    }

    listado << std::setw(93) << std::right << "$" << total_ventas();
    listado << std::endl;

    return listado.str();
}

std::string Vendedor::generar_listado_2() {
    std::stringstream listado;

    listado << std::setw(24) << std::left << codigo;
    listado << std::setw(20) << std::left << cantidad_total();
    return listado.str();
}

std::string Vendedor::generar_listado_3() {
    std::stringstream listado;

    listado << std::setw(24) << std::left << codigo;
    listado << "$" << std::setw(20) << std::left << total_ventas();
    return listado.str();
}


float Vendedor::total_ventas() {
    float total = 0;
    for(int i = 0; i < ventas.size(); i++) {
        total += ventas[i].precio_total();
    }

    return total;
}

int Vendedor::cantidad_total() {
    int total = 0;
    for (int i = 0; i < ventas.size(); i++) {
        total += ventas[i].cantidad;
    }
    return total;
}

int xxxxxxxx(int id, std::vector<Vendedor>& vendedores) {
    for (int i = 0; i < vendedores.size(); i++) {
        if (id == vendedores[i].codigo)
            return i;
    }
    Vendedor vendedor = { id };
    vendedores.push_back(vendedor);
    return vendedores.size() - 1;
}

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

    std::ifstream archivo(nombre);
    while(getline(archivo, linea)) {
        leer_y_registrar_venta(linea, vendedores);
    }
}

bool ordenar_vendedores_por_codigo(Vendedor vendedor1, Vendedor vendedor2) {
    return vendedor1.codigo > vendedor2.codigo;
}

bool ordenar_vendedores_por_cantidad_articulos(Vendedor vendedor1, Vendedor vendedor2) {
    return vendedor1.cantidad_total() > vendedor2.cantidad_total();
}

bool ordenar_vendedores_por_total_ventas(Vendedor vendedor1, Vendedor vendedor2) {
    return vendedor1.total_ventas() > vendedor2.total_ventas();
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
