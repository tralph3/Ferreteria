#ifndef _UTILS_H
#define _UTILS_H

#include <vector>
#include <string>

float string_to_float(const std::string&);

int string_to_int(const std::string&);

void split_string(std::string, std::vector<std::string>&, char);

std::string float_to_string(float);

void write_to_file(std::string, std::string);

#endif
