//Question 1 — Inventory Management System
//Part A — Product class with Array of Objects

#include<iostream>
using namespace std;

class Product{
    static int productId;
    string name;
    double price;
    int quantity;
    int thisID;

public:
    Product(){
       thisID = productId++;
    }
    
    void setName (const string& n){
        if(n != "" && n != " "){
            name = n;
        }
        else{
            cout<<"Name cannot be empty!"<<endl;
        }
    }

    void setPrice(double p){
        price = p;
    }

    void setQuantity(int q){
        if(q > 0){
            quantity = q;
        }
    }

    

    int getProductId() const {
        return this->thisID;
    }
    string getName() const {
        return name;
    }
    
    double getPrice() const {
        return this->price;
    }
     int getQuantity()const {
        return this->quantity;
    }
    


    void acceptDetails(){
        // Read all fields from user
     
        string name;
        double price;
        int quantity;

        cout<<"Enter the name :"<<endl;
        cin>>name;
        setName(name);

        cout<< "Enter the price :" <<endl;
        cin>>price;
        if(price > 0){
            setPrice(price);
        }else{
            cout<< "Enter the right price :"<<endl;
        }
        
        cout<< "Enter the quantity" <<endl;
        cin>>quantity;
        setQuantity(quantity);

    } 
    void displayDetails(int threshold) const{
        double price = getPrice();
        int quantity = getQuantity();
        double TotalValue = totalValue(price,quantity);

        bool stock = isLowStock(threshold);

        
        cout<<getProductId() << "\t" << getName() << "\t" <<price << "\t" << quantity << "\t" << TotalValue << (stock?" \t\t<-LOW STOCK" : "") << endl ;

    } // Print formatted product info
    double totalValue(double price , int quantity) const{
        return price* quantity;

    }
        // price * quantity
    bool isLowStock(int threshold) const{
        int quantity = getQuantity();

        if(quantity < threshold){
            return true;
        }else{
            return false;
        }
    } 
    // true if quantity < threshold

    void highestValueProduct(Product prod[] , int size){
        int price = prod[0].getPrice();
        int quantity = prod[0].getQuantity();
        string productName = prod[0].getName();

        int maxValue = price * quantity;

        for(int i = 1 ; i<size ; i++){
            price = prod[i].getPrice();
            quantity = prod[i].getQuantity();
            int TotalValue = price * quantity;
            if(TotalValue > maxValue ){
                maxValue = TotalValue;
                productName = prod[i].getName();
            }
        }

        cout<< "Highest Value Product : "<< productName <<" (Rs. "<< maxValue << " ) " <<endl;
        
    }
    bool found = false;
    void lowStockThreshold(Product prod[] , int size , int threshold){
        cout<< "Low Stock (threshold: "<<threshold<<" ) : ";
        for(int i = 0; i < size ; i++ ){
            if(prod[i].getQuantity() <= threshold){
                if(found){
                    cout << " , " ;
                }
                cout<< prod[i].getName() << " , ";
                found = true;
            }
        }
        if (!found)
        cout << "None";


    }

};


int Product::productId = 1001;

int main(){
    int size;
    cout<<"Enter the size of the array : ";
    cin>> size;

    

    Product prod[size];

    for(int i = 0;i<size;i++){
        cout<<"Enter the data for PRODUCT "<< i+1<< endl;
        prod[i].acceptDetails();
    }

     int threshold;
    cout<< "Enter the threshold : ";
    cin>>threshold;

    cout<<"======== INVENTORY REPORT ========"<<endl;
    cout<<"ID \tName \tprice \tQty \tTotal Value"<<endl;
    for(int i = 0;i<size;i++){
        prod[i].displayDetails(threshold);
    } 

    Product prod1;
    prod1.highestValueProduct(prod , size);
    prod1.lowStockThreshold(prod,size,threshold);
    return 0;
}