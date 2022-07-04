#include <iomanip>
#include "listings.h"

std::string Listing::make_entry(std::vector<std::string>& values) {
    if(values.size() != column_number)
        throw std::invalid_argument("values don\'t fit in this listing");

    std::stringstream stream;
    for (size_t i = 0; i < values.size(); i++) {
        stream << std::setw(column_sizes[i]) << std::left << values[i];
    }
    stream << std::endl;
    return stream.str();
}
