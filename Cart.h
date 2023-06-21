#ifndef CART_H_INCLUDED
#define CART_H_INCLUDED

#include <map>

using namespace std;

class Cart{
public:
    float get_total_price();
    void add(int, int);
    void remove_item(int);
    void print() const;
    void reset();

    map<int,int> get_items(){ return items; }
    float find_price(int);
    int return_quantity(int id){ return items[id]; }
private:
    map<int, int> items;
    float total_price = 0;
};

#endif // CART_H_INCLUDED
