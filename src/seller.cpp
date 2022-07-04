#include <algorithm>
#include <fstream>
#include <stdexcept>
#include <vector>
#include "seller.h"
#include "sale.h"

void Seller::register_sale(Sale& sale) {
    sales.push_back(sale);
}

std::vector<Sale>& Seller::get_sales() {
    return sales;
}

float Seller::total_sales() {
    float total = 0;
    for(size_t i = 0; i < sales.size(); i++) {
        total += sales[i].total_price();
    }

    return total;
}

int Seller::total_products() {
    int total = 0;
    for (size_t i = 0; i < sales.size(); i++) {
        total += sales[i].amount;
    }
    return total;
}

Seller& get_or_register_seller_by_id(int id, std::vector<Seller>& sellers) {
    for (size_t i = 0; i < sellers.size(); i++) {
        if (id == sellers[i].id)
            return sellers[i];
    }
    sellers.push_back(Seller(id));
    return sellers.back();
}

Seller& get_seller_with_most_sales(std::vector<Seller>& sellers) {
    // get min to reverse order
    return *std::min_element(
        sellers.begin(), sellers.end(), sort_sellers_by_total_sales);
}

void read_and_register_sale(std::string& line, std::vector<Seller>& sellers) {
    std::vector<std::string> ticket;
    split_string(line, ticket, '\t');
    if (ticket.size() != 7)
        throw std::invalid_argument("sales should have seven elements");

    Date date;
    date.day = string_to_int(ticket[4]);
    date.month = string_to_int(ticket[5]);
    date.year = string_to_int(ticket[6]);

    Sale sale;
    sale.amount = string_to_int(ticket[1]);
    sale.description = ticket[2];
    sale.unit_price = string_to_float(ticket[3]);
    sale.date = date;

    int seller_id = string_to_int(ticket[0]);
    Seller& seller = get_or_register_seller_by_id(seller_id, sellers);
    seller.register_sale(sale);
}

void read_sales(std::vector<Seller>& sellers, const char* file_name) {
    std::string line;

    std::ifstream file(file_name);
    while(getline(file, line)) {
        read_and_register_sale(line, sellers);
    }
}

bool sort_sellers_by_id(Seller seller1, Seller seller2) {
    return seller1.id > seller2.id;
}

bool sort_sellers_by_total_products(Seller seller1, Seller seller2) {
    return seller1.total_products() > seller2.total_products();
}

bool sort_sellers_by_total_sales(Seller seller1, Seller seller2) {
    return seller1.total_sales() > seller2.total_sales();
}

float grand_total(std::vector<Seller>& sellers) {
    float total = 0;
    for (size_t i = 0; i < sellers.size(); i++) {
        total += sellers[i].total_sales();
    }
    return total;
}
