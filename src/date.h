#ifndef _DATE_H
#define _DATE_H

#include <string>

struct Date {
    short day;
    short month;
    int year;

    std::string to_string();
};

#endif
