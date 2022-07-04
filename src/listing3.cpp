#include <sstream>
#include <iomanip>
#include <algorithm>
#include <stdexcept>
#include <string>
#include <vector>
#include "utils.h"
#include "seller.h"
#include "listings.h"


std::string Listing3::make_header() {
    std::vector<std::string> header;
    header.push_back("Codigo de Vendedor");
    header.push_back("Importe Total");
    return make_entry(header);
}

std::string Listing3::make_listing(std::vector<Seller>& sellers) {
    std::sort(sellers.begin(), sellers.end(), sort_sellers_by_total_sales);
    std::stringstream stream;
    stream << make_header();
    std::vector<std::string> values;
    for (size_t i = 0; i < sellers.size(); i++) {
        values.push_back(int_to_string(sellers[i].id));
        values.push_back(float_to_string(sellers[i].total_sales()));
        stream << make_entry(values);
        values.clear();
    }
    return stream.str();
}
