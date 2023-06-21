#include "Receipt.h"
#include "Store.h"

float Receipt::find_price(int id){
    for(int i = 0;  i < Store::get_number_of_products(); ++i)
        if(Store::get_product(i).get_id_of_product() == id){
            return Store::get_product(i).get_price_of_product();
            break;
        }
    throw invalid_argument("One of the product is not exsit!");
}

float Receipt::get_total_price(){
    for(auto it = items.begin(); it != items.end(); ++it)
        total_price += (find_price(it->first) * it->second);
    return total_price;
}

string Receipt::get_date(){
    string month, day;
    if(date.getMonth() < 10)
        month = "0" + to_string(date.getMonth());
    else
        month = to_string(date.getMonth());
    if(date.getDay() < 10)
        day = "0" + to_string(date.getDay());
    else
        day = to_string(date.getDay());
    string d = "";
    d = (to_string(date.getYear()) + "/" + month + "/" + day);
    return d;
}

string Receipt::get_items_for_file(){
    string s = "";
    for(auto it = items.begin(); it != items.end(); ++it)
        s += to_string(it->first) + " " + to_string(it->second) + " ";
    return s;

}
