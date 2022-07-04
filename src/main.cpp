#include <iostream>
#include <sstream>
#include "seller.h"
#include "listings.h"
#include "utils.h"

int main()
{
    std::vector<Seller> sellers;
    read_sales(sellers, "./VentasFerreteria.txt");

    Listing1 listing1;
    Listing2 listing2;
    Listing3 listing3;

    std::stringstream stream;
    stream << listing1.make_listing(sellers);
    stream << "\n---------------------------------\n" << std::endl;
    stream << listing2.make_listing(sellers);
    stream << "\n---------------------------------\n" << std::endl;
    stream << listing3.make_listing(sellers);

    write_to_file("./Listados.txt", stream.str());
    return 0;
}

