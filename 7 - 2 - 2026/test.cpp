#include <iostream>
#include <string>
using namespace std;

/* ===================== MEDICINE CLASS ===================== */
class Medicine {
private:
    string name;
    string manufacturer;
    string category;
    double price;
    int quantity;
    string expiryDate;

public:
    Medicine() {
        name = "Unknown";
        manufacturer = "Unknown";
        category = "General";
        price = 0.0;
        quantity = 0;
        expiryDate = "N/A";
        cout << "Medicine created (default)\n";
    }

    Medicine(string n, string m, string c, double p, int q, string exp) {
        name = n;
        manufacturer = m;
        category = c;
        price = p;
        quantity = q;
        expiryDate = exp;
        cout << "Medicine created: " << name << endl;
    }

    Medicine(const Medicine& other) {
        name = other.name;
        manufacturer = other.manufacturer;
        category = other.category;
        price = other.price;
        quantity = other.quantity;
        expiryDate = other.expiryDate;
        cout << "Medicine copied: " << name << endl;
    }

    ~Medicine() {
        cout << "Medicine destroyed: " << name << endl;
    }

    string getName() const { return name; }
    string getCategory() const { return category; }
    double getPrice() const { return price; }
    int getQuantity() const { return quantity; }

    void setPrice(double p) {
        if (p >= 0) price = p;
    }

    void setQuantity(int q) {
        if (q >= 0) quantity = q;
    }

    bool isExpired(string currentDate) const {
        return expiryDate < currentDate;
    }

    bool isOverstocked(int threshold) const {
        return quantity > threshold;
    }

    void sell(int amount) {
        if (amount <= quantity)
            quantity -= amount;
        else
            cout << "Insufficient stock!\n";
    }

    double totalValue() const {
        return price * quantity;
    }

    void display() const {
        cout << "\n--- Medicine Details ---\n";
        cout << "Name: " << name << endl;
        cout << "Manufacturer: " << manufacturer << endl;
        cout << "Category: " << category << endl;
        cout << "Price: $" << price << endl;
        cout << "Quantity: " << quantity << endl;
        cout << "Expiry: " << expiryDate << endl;
    }
};

/* ===================== CUSTOMER CLASS ===================== */
class Customer {
private:
    string name;
    string phone;
    int loyaltyPoints;

public:
    Customer(string n = "Unknown", string p = "N/A") {
        name = n;
        phone = p;
        loyaltyPoints = 0;
    }

    void addPoints(int pts) {
        loyaltyPoints += pts;
    }

    void redeemPoints(int pts) {
        if (pts <= loyaltyPoints)
            loyaltyPoints -= pts;
    }

    void display() const {
        cout << "Customer: " << name
             << " | Phone: " << phone
             << " | Points: " << loyaltyPoints << endl;
    }
};

/* ===================== PHARMACY CLASS ===================== */
class Pharmacy {
private:
    Medicine* inventory;
    int inventorySize;

public:
    Pharmacy() {
        inventory = nullptr;
        inventorySize = 0;
    }

    ~Pharmacy() {
        delete[] inventory;
        cout << "Pharmacy closed\n";
    }

    void addMedicine(const Medicine& m) {
        Medicine* temp = new Medicine[inventorySize + 1];
        for (int i = 0; i < inventorySize; i++)
            temp[i] = inventory[i];

        temp[inventorySize] = m;
        delete[] inventory;
        inventory = temp;
        inventorySize++;
    }

    Medicine* findByName(string name) {
        for (int i = 0; i < inventorySize; i++)
            if (inventory[i].getName() == name)
                return &inventory[i];
        return nullptr;
    }

    void findByCategory(string category) {
        for (int i = 0; i < inventorySize; i++)
            if (inventory[i].getCategory() == category)
                inventory[i].display();
    }

    bool removeMedicine(string name) {
        int index = -1;
        for (int i = 0; i < inventorySize; i++) {
            if (inventory[i].getName() == name) {
                index = i;
                break;
            }
        }

        if (index == -1)
            return false;

        for (int i = index; i < inventorySize - 1; i++)
            inventory[i] = inventory[i + 1];

        inventorySize--;
        return true;
    }

    double getTotalInventoryValue() const {
        double sum = 0;
        for (int i = 0; i < inventorySize; i++)
            sum += inventory[i].totalValue();
        return sum;
    }

    void listOverstockedMedicines(int threshold) {
        for (int i = 0; i < inventorySize; i++)
            if (inventory[i].isOverstocked(threshold))
                inventory[i].display();
    }

    Medicine* getMostExpensive() {
        if (inventorySize == 0)
            return nullptr;

        int idx = 0;
        for (int i = 1; i < inventorySize; i++)
            if (inventory[i].getPrice() > inventory[idx].getPrice())
                idx = i;

        return &inventory[idx];
    }

    Medicine* getCheapest() {
        if (inventorySize == 0)
            return nullptr;

        int idx = 0;
        for (int i = 1; i < inventorySize; i++)
            if (inventory[i].getPrice() < inventory[idx].getPrice())
                idx = i;

        return &inventory[idx];
    }

    double getAveragePrice() const {
        if (inventorySize == 0)
            return 0;

        double sum = 0;
        for (int i = 0; i < inventorySize; i++)
            sum += inventory[i].getPrice();

        return sum / inventorySize;
    }

    void generateReport() {
        cout << "\n=== PHARMACY REPORT ===\n";
        cout << "Total medicines: " << inventorySize << endl;
        cout << "Inventory value: $" << getTotalInventoryValue() << endl;
        cout << "Average price: $" << getAveragePrice() << endl;

        if (getMostExpensive()) {
            cout << "\nMost Expensive:\n";
            getMostExpensive()->display();
        }

        if (getCheapest()) {
            cout << "\nCheapest:\n";
            getCheapest()->display();
        }
    }

    void displayInventory() {
        for (int i = 0; i < inventorySize; i++)
            inventory[i].display();
    }
};

/* ===================== DISCOUNT FUNCTIONS ===================== */
void applyDiscount1(Medicine m, double percent) {
    m.setPrice(m.getPrice() * (1 - percent / 100));
}

void applyDiscount2(Medicine& m, double percent) {
    m.setPrice(m.getPrice() * (1 - percent / 100));
}

void applyDiscount3(Medicine* m, double percent) {
    if (m)
        m->setPrice(m->getPrice() * (1 - percent / 100));
}

/* ===================== SAFE POINTER FUNCTIONS ===================== */
Medicine* createMedicine(string name, double price) {
    return new Medicine(name, "Generic", "General", price, 10, "2027-01-01");
}

Medicine* findCheapest(Medicine* arr, int size) {
    if (size == 0)
        return nullptr;

    int idx = 0;
    for (int i = 1; i < size; i++)
        if (arr[i].getPrice() < arr[idx].getPrice())
            idx = i;

    return &arr[idx];
}

/* ===================== MAIN ===================== */
int main() {
    Pharmacy pharmacy;

    pharmacy.addMedicine(
        Medicine("Aspirin", "Bayer", "Pain Relief", 5.99, 100, "2026-12-31")
    );
    pharmacy.addMedicine(
        Medicine("Amoxicillin", "Pfizer", "Antibiotic", 12.5, 30, "2025-10-01")
    );

    pharmacy.displayInventory();
    pharmacy.generateReport();

    Medicine test(
        "Paracetamol", "Cipla", "Pain Relief", 10, 50, "2024-01-01"
    );

    applyDiscount1(test, 10);
    applyDiscount2(test, 10);
    applyDiscount3(&test, 10);

    test.display();

    return 0;
}
