#include "Store.h"

Store::Store(Date d1){
    set_number_of_customers(0);
    set_number_of_products(0);
    set_date_of_today(d1);

    ifstream infor("store.txt");
    string check, id, name, price, stock, date, brand, phone_number, address, balance;
    map<int, int> items_of_receipt;
    string first, second, number_of_receipts;
    Date date_of_receipt;

    infor >> check;
    while(check != "Customers:" && !infor.eof()){
        infor >> id >> id >> id;
        infor >> name >> name >> name;
        infor >> brand >> brand >> brand;
        infor >> stock >> stock >> stock;
        infor >> price >> price >> price;
        infor >> date >> date >> date;
        Store::add_to_product_by_file(id, name, brand, stock, price, date);
        infor >> check;
    }

    while(!infor.eof() && check != "End-Of-File"){
        infor >> id >> id >> id;
        infor >> name >> name >> name;
        infor >> phone_number >> phone_number>> phone_number;
        infor >> address >> address >> address;
        infor >> balance >> balance >> balance;
        infor >> number_of_receipts >> number_of_receipts >> number_of_receipts;
        Store::add_to_customer_by_file(id, name, phone_number, balance, address, number_of_receipts);
        for(int j = 0; j < stoi(number_of_receipts); ++j){
            infor >> date >> date >> date;
            date_of_receipt.cast_to_date(date);
            infor >> first >> first;
            for(int i = 0; i < Store::number_of_products; ++i){
                infor >> first >> second;
                items_of_receipt[stoi(first)] = stoi(second);
            }
            Receipt temp(items_of_receipt, date_of_receipt);
            list_of_customers[stoi(id)].add_receipt(temp);
        }
        infor >> check;
    }
    infor.close();

}

Store::~Store(){
    save_to_file();
}

void Store::check_out(int id){
    Store::list_of_customers[id].convert_cart_to_receipt();
}

void Store::add_cusotmer(){
    int n;
    string name, phone, address;
    float balance;
    cout << "Id: ";
    cin >> n;

    cout << "Name: ";
    cin >> name;

    cout << "Phone Number: ";
    cin >> phone;

    cout << "Address: ";
    cin >> address;

    cout << "Balance: ";
    cin >> balance;
    unsigned int nr = 0;
    Customer temp(n, name, phone, address, balance, nr);
    list_of_customers[get_number_of_customers()] = temp;
    number_of_customers++;
}

void Store::add_product(){
    int n, stock;
    string name, brand;
    float price;
    Date ex;

    cout << "Id: ";
    cin >> n;

    cout << "Name: ";
    cin >> name;

    cout << "Price: ";
    cin >> price;

    cout << "Brand: ";
    cin >> brand;

    cout << "Expire Date: ";
    cin >> ex;

    cout << "Stock: ";
    cin >> stock;

    Product temp(n, name, price, brand, ex, stock);
    list_of_products[number_of_products] = temp;
    number_of_products++;
}

void Store::view_products(){
    for(int i = 0; i < get_number_of_products(); ++i)
        list_of_products[i].print_product();
}

void Store::save_to_file(){
    ofstream save("store.txt");
    save << "Products:" << endl;
    string temp;
    for(int i = 0; i < get_number_of_products(); ++i){
        if(i != 0)
            save << "(product) ";
        temp = list_of_products[i].print_product_in_file();
        save << temp;
        save << endl;
    }
    save << "Customers:" << endl;
    for(int i = 0; i < get_number_of_customers(); ++i){
        if(i != 0)
            save << "(customer) ";
        temp = list_of_customers[i].print_customer_in_file();
        save << temp;
        save << endl;
        for(int j = 0; j < list_of_customers[i].get_number_of_receipts(); ++j){
            temp = list_of_customers[i].print_receipts(i);
            save << temp;
            if(j != list_of_customers[i].get_number_of_receipts() - 1)
                save << endl;
        }
        if(i != get_number_of_customers() - 1)
            save << endl;
    }
    save << "End-Of-File";
    save.close();
}



void Store::sales_report(string d1, string d2){
    Date temp;
    Date ds(d1), de(d2);
    for(int i = 0; i < get_number_of_customers() ; ++i){
        for(int j = 0; j < list_of_customers[i].get_number_of_receipts(); ++j){
            temp.cast_to_date(list_of_customers[i].get_receipt(j).get_date());
            if(temp <= ds && de <= temp)
                cout << "Date : " << list_of_customers[i].get_receipt(j).get_date();
                cout << " " << list_of_customers[i].get_receipt(j).get_total_price() << endl;
        }
    }
}

void Store::add_to_customer_by_file(string &id, string &name, string &phone, string &balance, string &address, string &num){
    int n = stoi(id);
    float b = stof(balance);
    unsigned int rece = stoi(num);
    Customer temp(n, name, phone, address, b, rece);
    list_of_customers[get_number_of_customers()] = temp;
    number_of_customers++;
}

void Store::add_to_product_by_file(string &id, string &name, string &brand, string &s, string &p, string &date){
    int n = stoi(id);
    int stock = stoi(s);
    float price = stof(p);
    Date ex;
    ex.cast_to_date(date);
    Product temp(n, name, price, brand, ex, stock);
    list_of_products[number_of_products] = temp;
    number_of_products++;
}
