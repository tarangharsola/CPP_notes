/*
Create the medicine class Question: 
Write the description of the class and indicate what does it do ?


*/

#include <iostream>
#include <string>
using namespace std;


class Medicine {
private:
    string name;
    double price;
    int quantity;
    string expiryDate;
    
public:

Medicine(string n, double p, int q, string exp) {
        name = n;
        price = p;
        quantity = q;
        expiryDate = exp;
        cout << "Medicine created: " << name << endl;
    }
Medicine(Medicine& j)
{
    this->expiryDate = j.expiryDate;
    this->name = j.name;
}

Medicine(int i):quantity(i)
{

}
    you have other constructors
    Medicine() {
        name = "Unknown";
        price = 0.0;
        quantity = 0;
        expiryDate = "N/A";
    }
    
        ~Medicine() {
        cout << "Medicine destroyed: " << name << endl;
    }
    
    // GETTER METHODS (Accessors) - Same as Java
    string getName() {
        return name;
    }
    
    double getPrice() {
        return price;
    }
    
    int getQuantity() {
        return quantity;
    }
    
    string getExpiryDate() {
        return expiryDate;
    }
    
    // SETTER METHODS (Mutators) - Same as Java
    void setPrice(double p) {
        if (p >= 0) {
            price = p;
        }
    }
    
    void setQuantity(int q) {
        if (q >= 0) {
            quantity = q;
        }
    }
    
    void sell(int amount) {
        if (amount <= quantity) {
            quantity -= amount;
            cout << "Sold " << amount << " units of " << name << endl;
            cout << "Remaining quantity: " << quantity << endl;
        } else {
            cout << "Insufficient stock! Only " << quantity << " available." << endl;
        }
    }
    
    void restock(int amount) {
        quantity += amount;
        cout << "Restocked " << amount << " units of " << name << endl;
    }
    
    double calculateTotal(int amount) {
        return price * amount;
    }
    
    // Display method - like toString() in Java
    void display() {
        cout << "\n--- Medicine Details ---" << endl;
        cout << "Name: " << name << endl;
        cout << "Price: $" << price << endl;
        cout << "Quantity: " << quantity << endl;
        cout << "Expiry: " << expiryDate << endl;
    }
    
    
    void displayConst() const {
        cout << name << " - $" << price << endl;
        // price = 100; // ERROR! Can't modify in const method
    }
};

