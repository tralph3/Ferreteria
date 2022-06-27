#include <sstream>
#include <string>
#include <vector>
#include <stdexcept>
#include <iomanip>

void split_string(
    std::string string, std::vector<std::string>& vector, char separator
) {
    std::string temp = "";
    for(int i = 0; i < string.length(); i++){
        if (string[i] == separator) {
            vector.push_back(temp);
            temp = "";
        } else {
            temp.push_back(string[i]);
        }

    }
    vector.push_back(temp);
}

int string_to_int(const std::string& string) {
    std::stringstream str(string);
    int num;
    if((str >> num).fail())
    {
        throw std::invalid_argument("Cant parse to int");
    }
    return num;
}

float string_to_float(const std::string& string) {
    std::stringstream str(string);
    float num;
    if((str >> num).fail())
    {
        throw std::invalid_argument("Cant parse to float");
    }
    return num;
}

void generar_cabecera(std::stringstream& stream) {
    stream << std::setw(10) << std::left << "#Item";
    stream << std::setw(12) << std::left << "Fecha";
    stream << std::setw(10) << std::left << "Cantidad";
    stream << std::setw(25) << std::left << "Descripcion";
    stream << std::setw(20) << std::left << "Precio por Unidad";
    stream << std::setw(15) << std::left << "Total Item";
    stream << std::setw(15) << std::left << "Total Venta";
    stream << std::endl;
}
