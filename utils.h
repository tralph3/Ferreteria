#ifndef _UTILS_H
#define _UTILS_H

#include <string>
#include <vector>

float string_to_float(const std::string& string);

int string_to_int(const std::string& string);

void split_string(
    std::string string, std::vector<std::string>& vector, char separator
);

#endif
