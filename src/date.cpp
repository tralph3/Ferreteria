#include <iomanip>
#include <sstream>
#include "date.h"

std::string Date::to_string() {
    std::stringstream stream;
    stream << std::setfill('0') << std::setw(2) << day;
    stream << "/";
    stream << std::setfill('0') << std::setw(2) << month;
    stream << "/";
    stream << std::setfill('0') << std::setw(4) << year;
    return stream.str();
}
