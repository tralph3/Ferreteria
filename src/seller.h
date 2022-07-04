#ifndef _SELLER_H
#define _SELLER_H

#include <vector>
#include "sale.h"
#include "utils.h"

struct Seller {
private:
    std::vector<Sale> sales;
public:
    int id;

    Seller(int id): id(id){}

    std::vector<Sale>& get_sales();

    void register_sale(Sale&);

    float total_sales();

    int total_products();

};

Seller& get_or_register_seller_by_id(int, std::vector<Seller>&);

Seller& get_seller_with_most_sales(std::vector<Seller>&);

void read_and_register_sale(std::string&, std::vector<Seller>&);

void read_sales(std::vector<Seller>&, const char*);

bool sort_sellers_by_id(Seller, Seller);

bool sort_sellers_by_total_products(Seller, Seller);

bool sort_sellers_by_total_sales(Seller, Seller);

float grand_total(std::vector<Seller>&);

#endif
