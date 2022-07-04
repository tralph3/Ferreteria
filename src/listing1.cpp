#include <sstream>
#include <iomanip>
#include <algorithm>
#include <stdexcept>
#include <string>
#include <vector>
#include "utils.h"
#include "seller.h"
#include "listings.h"


std::string Listing1::make_header() {
    std::vector<std::string> header;
    header.push_back("#Item");
    header.push_back("Fecha");
    header.push_back("Cantidad");
    header.push_back("Descripcion");
    header.push_back("Precio por Unidad");
    header.push_back("Total Item");
    header.push_back("Total Venta");
    return make_entry(header);
}

std::string Listing1::make_footer(std::vector<Seller>& sellers) {
    std::stringstream stream;
    char padding = 0;
    for(short i = 0; i < (column_number - 1); i++)
        padding += column_sizes[i];

    Seller& seller_with_most_sales = get_seller_with_most_sales(sellers);
    stream << std::setfill('.') << std::setw(padding);
    stream << std::left << "Total General";
    stream << std::right << "$" << float_to_string(grand_total(sellers)) << std::endl;
    stream << "Codigo del vendedor con mayor ventas: ";
    stream << seller_with_most_sales.id << std::endl;
    return stream.str();
}

std::string Listing1::make_listing(std::vector<Seller>& sellers) {
    std::sort(sellers.begin(), sellers.end(), sort_sellers_by_id);
    std::stringstream stream;
    std::vector<std::string> values;
    for (size_t i = 0; i < sellers.size(); i++) {
        stream << "Codigo de vendedor: " << sellers[i].id << std::endl;
        stream << make_header();
        std::vector<Sale>& sales = sellers[i].get_sales();
        for (size_t j = 0; j < sales.size(); j++) {
            values.push_back(int_to_string(j + 1));
            values.push_back(sales[j].date.to_string());
            values.push_back(int_to_string(sales[j].amount));
            values.push_back(sales[j].description);
            values.push_back("$" + float_to_string(sales[j].unit_price));
            values.push_back("$" + float_to_string(sales[j].total_price()));
            if (j == sales.size() - 1)
                values.push_back("$" + float_to_string(sellers[i].total_sales()));
            else
                values.push_back("");
            stream << make_entry(values);
            values.clear();
        }
        stream << std::endl;
    }
    stream << make_footer(sellers);
    return stream.str();
}
