#ifndef RECEIPT_H_INCLUDED
#define RECEIPT_H_INCLUDED

#include "Date.h"
#include <map>

using namespace std;

class Receipt{
public:
    Receipt() {}
    Receipt(map<int, int> &item, Date &d){ items = item; date = d; }

    float get_total_price();
    float find_price(int);

    void set_date(Date d){ date = d; }
    void set_items(map<int, int> a){ items = a; }
    string get_date();
    string get_items_for_file();

private:
    std::map<int, int> items;
    Date date;
    float total_price = 0;
};

#endif // RECEIPT_H_INCLUDED
