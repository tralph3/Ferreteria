#ifndef _LISTINGS_H
#define _LISTINGS_H

#include <sstream>
#include <vector>
#include "seller.h"

struct Listing {
    std::vector<unsigned char> column_sizes;
    unsigned char column_number;

    virtual std::string make_header() = 0;

    virtual std::string make_listing(std::vector<Seller>&) = 0;

    virtual ~Listing(){}

protected:
    virtual std::string make_entry(std::vector<std::string>&);
};

struct Listing1 : Listing {
private:
    std::string make_header();

    std::string make_footer(std::vector<Seller>&);

public:
    Listing1() {
        column_sizes.push_back(10);
        column_sizes.push_back(15);
        column_sizes.push_back(12);
        column_sizes.push_back(25);
        column_sizes.push_back(20);
        column_sizes.push_back(15);
        column_sizes.push_back(15);
        column_number = column_sizes.size();
    }

    std::string make_listing(std::vector<Seller>&);
};

struct Listing2 : Listing {
private:
    std::string make_header();

public:
    Listing2() {
        column_sizes.push_back(25);
        column_sizes.push_back(20);
        column_number = column_sizes.size();
    }

    std::string make_listing(std::vector<Seller>&);
};

struct Listing3 : Listing {
private:
    std::string make_header();

public:
    Listing3() {
        column_sizes.push_back(25);
        column_sizes.push_back(20);
        column_number = column_sizes.size();
    }

    std::string make_listing(std::vector<Seller>&);
};

#endif
