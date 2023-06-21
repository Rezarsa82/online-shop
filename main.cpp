#include <iostream>
#include "Stock.h"
#include "Store.h"

using namespace std;

void decide(string&, Store&);

Product Store::list_of_products[MAX_SIZE];
Customer Store::list_of_customers[MAX_SIZE];
unsigned int Store::number_of_products;
unsigned int Store::number_of_customers;
Date Store::date_of_today;
map<int, int> Stock::stock_of_products;

int main()
{
    Date d1(2022,03,23);
    Store s1(d1);
    try
    {
        string s;
        cin >> s;
        while(s != "Exit"){
            decide(s, s1);
            cin >> s;
        }
    }
    catch(exception &err)
    {
        cout << "Error occured: " << err.what() << endl;
    }
    return 0;
}

void decide(string &d, Store &s1){
    int n, m, l;
    string d1, d2;

    if(d == "View-product")
        s1.view_products();

    if(d == "Print-customer"){
        cin >> n;
        s1.get_customer(n).print_customer();
    }

    if(d == "Add-customer")
        s1.add_cusotmer();

    if(d == "Add"){
        cin >> n;
        cin >> m;
        cin >> l;
        s1.get_customer(n).get_cart().add(m, l);
    }

    if(d == "Print-cart"){
        cin >> n;
        s1.get_customer(n).get_cart().print();
    }

    if(d == "Total-price"){
        cin >> n;
        cout << s1.get_customer(n).get_cart().get_total_price();
    }

    if(d == "Remove-item"){
        cin >> n;
        cin >> m;
        s1.get_customer(n).get_cart().remove_item(m);
    }

    if(d == "add-product")
         s1.add_product();

    if(d == "save-to-file")
        s1.save_to_file();
/*
    if(d == "convert-to-receipt"){
       cin >> n;
       s1.get_customer(n).convert_cart_to_receipt(s1.get_customer(n).get_cart());
    }

    if(d == "sales-report"){
        cout << "Enter start date: ";
        cin >> d1;
        cout << "Enter end date: ";
        cin >> d2;
        s1.sales_report(d1, d2);
    }
*/
    if(d == "end-of-day")
        s1.tick();

}

