#include "vendedor.h"

void Vendedor::agregar_venta(Venta venta) {
    ventas.push_back(venta);
}

std::string Vendedor::generar_listado() {
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

float Vendedor::total_ventas() {
    float total = 0;
    for(int i = 0; i < ventas.size(); i++) {
        total += ventas[i].precio_total();
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
