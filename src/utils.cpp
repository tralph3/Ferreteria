#include <fstream>
#include <iomanip>
#include <sstream>
#include <string>
#include <vector>
#include <stdexcept>

void split_string(
    std::string string, std::vector<std::string>& vector, char separator
) {
    std::string temp = "";
    for(size_t i = 0; i < string.length(); i++){
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
        throw std::invalid_argument("Can\'t parse to int");
    }
    return num;
}

float string_to_float(const std::string& string) {
    std::stringstream str(string);
    float num;
    if((str >> num).fail())
    {
        throw std::invalid_argument("Can\'t parse to float");
    }
    return num;
}

std::string float_to_string(float x) {
    std::stringstream stream;
    stream.imbue(std::locale(""));
    stream << std::fixed << std::setprecision(2) << x;
    return stream.str();
}

std::string int_to_string(int x) {
    std::stringstream stream;
    stream << x;
    return stream.str();
}

void write_to_file(std::string file_name, std::string contents) {
    std::ofstream file(file_name.c_str());
    file << contents;
}
