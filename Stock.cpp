#include "Stock.h"

void Stock::setStock(int id, int st){
    stock_of_products[id] = st;
}

void Stock::change_count_by(int product_id, int count){
    if(stock_of_products.find(product_id) == stock_of_products.end())
        throw invalid_argument("There is no product with this id!");
    else
        stock_of_products[product_id] += count;
}
