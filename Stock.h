#ifndef STOCK_H_INCLUDED
#define STOCK_H_INCLUDED

#include <map>

using namespace std;

class Stock{
public:
    Stock();

    int get_count(int id);
    static void change_count_by(int, int);
    static int get_stock_of_product(int id){ return stock_of_products[id]; }
    static void setStock(int, int);
    static map<int,int> get_stock_of_products();

private:
    static map<int, int> stock_of_products;
};

#endif // STOCK_H_INCLUDED
