#include "Cart.h"
#include "Store.h"
#include "Stock.h"

float Cart::get_total_price(){
    for(auto it = items.begin(); it != items.end(); ++it)
        total_price += (find_price(it->first) * it->second);
    return total_price;
}

float Cart::find_price(int id){
    for(int i = 0;  i < Store::get_number_of_products(); ++i)
        if(Store::get_product(i).get_id_of_product() == id)
            return Store::get_product(i).get_price_of_product();
    throw invalid_argument("One of the products is not exsit!");
}

void Cart::add(int product_id, int quantity){
    if(quantity > Stock::get_stock_of_product(product_id))
        throw runtime_error("Stock is less than quantity!");
    items.insert(pair<int, int>(product_id, quantity));
}

void Cart::remove_item(int product_id){
    items.erase(product_id);
}

void Cart::print() const{
    for(auto it = items.begin(); it != items.end(); ++it){
        Store::get_product(it->first).print_product();
        cout << "Quantity of this product in cart: " << it->second << endl;
    }
    cout << endl;
}

void Cart::reset(){
    items.clear();
}
