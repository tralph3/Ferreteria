#ifndef _SALE_H
#define _SALE_H

#include <string>
#include "date.h"

struct Sale {
    int amount;
    std::string description;
    float unit_price;
    Date date;

    float total_price();
};

#endif
