//Question 1 — Inventory Management System
//Part B — Function Overloading

#include<iostream>
using namespace std;

double reorderCost(int qty, double unitPrice){
    // integer quantity
    return qty * unitPrice;

} 

double reorderCost(double qty, double unitPrice){    
    // fractional (by weight)
    return qty * unitPrice;
}

double reorderCost(int qty, double unitPrice, double taxRate){
    // with tax

    double cost = qty * unitPrice;
    return cost + (cost * taxRate / 100) ;

}

double applyDiscount(double price, double discountPercent=10 ){

   

    return price - (price * discountPercent / 100);
    
}

int main(){
    int qty1;
    double qty2;
    double unitPrice;
    double taxRate;
    double discountPercent1;

    cout<< "Enter the quantity in integer : " ;
    cin>> qty1;
    cout<< "Enter the quantity in fractions  : " ;
    cin>> qty2;
    cout<< "Enter the price per unit : " ;
    cin>> unitPrice;
    cout<< "Enter the percentage of tax : " ;
    cin>> taxRate;
    cout<< "Enter the discount ( By default 10 %/ discount, so enter more the 10 ) : " ;
    cin>> discountPercent1;
    

    double reorderCostValue = reorderCost(qty1,unitPrice);
    cout<< "Reorder Cost of integer is : " << reorderCostValue << endl;

    double reorderCostDouble = reorderCost(qty2,unitPrice);
    cout<< "Reorder Cost of double is : " << reorderCostDouble << endl;

    double reorderCostTax = reorderCost(qty1 , unitPrice , taxRate);
    cout<< "Integer With tax is: " << reorderCostTax << endl;

    double reorderCostTax1 = reorderCost(qty2 , unitPrice , taxRate);
    cout<< "Double With tax is: " << reorderCostTax1 << endl;
    
    cout << "Price After Discount: Rs. "<< applyDiscount(unitPrice, discountPercent1) << endl;

    cout << "Price After Default 10% Discount: Rs. "<< applyDiscount(unitPrice) << endl;

}