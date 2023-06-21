#include "Customer.h"
#include "Store.h"

Customer::Customer(int &i, string &n, string &ph, string &ad, float &b, unsigned int &num)
    : id(i), name(n), phone_number(ph), address(ad), balance(b), number_of_receipts(num) {}

void Customer::convert_cart_to_receipt(){
    if(check_balance(cart))
        throw runtime_error("Balance is not enough!");
    Receipt temp;
    temp.set_date(Store::get_date_of_today());
    temp.set_items(cart.get_items());
    list_of_receipts[number_of_calculated_receipts] = temp;
    number_of_calculated_receipts++;
    balance -= cart.get_total_price();
    change_stocks_of_cart();
}

float Customer::get_total_purchace_amount(){
    for(int i = 0; i < number_of_receipts; ++i)
        total_amount += list_of_receipts[i].get_total_price();
    return total_amount;
}

void Customer::change_stocks_of_cart(){
    for(auto it = cart.get_items().begin(); it != cart.get_items().end(); ++it)
                Stock::change_count_by(it->first, it->second);
}

bool Customer::check_balance(Cart &c){
    if(get_balance_of_customer() < c.get_total_price())
        return 0;
    return 1;
}

void Customer::print_customer(){
    cout << "Name: " << get_name_of_customer() << endl
         << "Id: "  << get_id_of_customer() << endl
         << "Address: "  << get_address_of_customer() << endl
         << "Phone Number: "  << get_phone_number_of_customer() << endl
         << "Balance: "  << get_balance_of_customer() << endl << endl;
}

string Customer::print_customer_in_file(){
    string customer_info = "";
    customer_info = "Id = " + to_string(get_id_of_customer())
         + " Name = " + get_name_of_customer()
         + " Phone-number = " + get_phone_number_of_customer()
         + " Address = " + get_address_of_customer()
         + " Balance = " + to_string(get_balance_of_customer())
         + " Number-of-receipts = " + to_string(get_number_of_receipts());
    return customer_info;
}

string Customer::print_receipts(int &i){
    string receipt_info = "";
    receipt_info = "Date = " + list_of_receipts[i].get_date()
        + " Items = " + list_of_receipts[i].get_items_for_file();
    return receipt_info;
}
