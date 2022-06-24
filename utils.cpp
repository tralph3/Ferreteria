#include <sstream>
#include <string>
#include <vector>
#include <stdexcept>

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
