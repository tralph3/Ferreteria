#ifndef _FECHA_H
#define _FECHA_H

#include <iostream>
#include <sstream>

struct Fecha {
    short dia;
    short mes;
    int ano;

    std::string to_string();
};

#endif
