#include <bits/stdc++.h>
#include <windows.h>
#include <fstream>
using namespace std;

// Base class: Product
class Product {
protected:
    int productID;
    char productName[51];
    float productPrice;
    int stockQuantity;

public:
    Product() {
        productID = 0;
        strcpy(productName, "No name");
        productPrice = 0.0;
        stockQuantity = 0;
    }

    virtual ~Product() {} // Virtual destructor for polymorphism

    virtual void inputProductDetails() {
        cout << "Enter product ID, name, price, and quantity: ";
        cin >> productID;
        cin.ignore();
        cin.getline(productName, 50);
        cin >> productPrice >> stockQuantity;
    }

    virtual void displayProductDetails() const {
        cout << "\nProduct ID: " << productID
             << "\nName: " << productName
             << "\nPrice: " << productPrice
             << "\nStock Quantity: " << stockQuantity << "\n";
    }

    virtual void saveToFile() = 0; // Pure virtual function for saving data
    virtual void loadFromFile() = 0; // Pure virtual function for loading data

    int getProductID() const { return productID; }

    virtual void displayCategoryDetails() const = 0; // Pure virtual for derived classes

    void setStockQuantity(int quantity) { stockQuantity = quantity; }
    int getStockQuantity() const { return stockQuantity; }

    float getProductPrice() const { return productPrice; }
    const char* getProductName() const { return productName; }
};

// Derived class: Grocery
class Grocery : public Product {
    char expiryDate[20];

public:
    void inputProductDetails() override {
        Product::inputProductDetails();
        cout << "Enter expiry date: ";
        cin.ignore();
        cin.getline(expiryDate, 20);
    }

    void displayProductDetails() const override {
        Product::displayProductDetails();
        cout << "Expiry Date: " << expiryDate << "\n";
    }

    void saveToFile() override {
        ofstream outFile("grocery.txt", ios::app | ios::binary);
        outFile.write((char*)this, sizeof(*this));
        outFile.close();
    }

    void loadFromFile() override {
        ifstream inFile("grocery.txt", ios::in | ios::binary);
        while (inFile.read((char*)this, sizeof(*this))) {
            displayProductDetails();
        }
        inFile.close();
    }

    void displayCategoryDetails() const override {
        cout << "Category: Grocery\n";
    }
};

// Derived class: Clothing
class Clothing : public Product {
    char size[10];

public:
    void inputProductDetails() override {
        Product::inputProductDetails();
        cout << "Enter size: ";
        cin.ignore();
        cin.getline(size, 10);
    }

    void displayProductDetails() const override {
        Product::displayProductDetails();
        cout << "Size: " << size << "\n";
    }

    void saveToFile() override {
        ofstream outFile("clothing.txt", ios::app | ios::binary);
        outFile.write((char*)this, sizeof(*this));
        outFile.close();
    }

    void loadFromFile() override {
        ifstream inFile("clothing.txt", ios::in | ios::binary);
        while (inFile.read((char*)this, sizeof(*this))) {
            displayProductDetails();
        }
        inFile.close();
    }

    void displayCategoryDetails() const override {
        cout << "Category: Clothing\n";
    }
};

// Derived class: Electronics
class Electronics : public Product {
    int warranty; // Warranty in months

public:
    void inputProductDetails() override {
        Product::inputProductDetails();
        cout << "Enter warranty period (in months): ";
        cin >> warranty;
    }

    void displayProductDetails() const override {
        Product::displayProductDetails();
        cout << "Warranty: " << warranty << " months\n";
    }

    void saveToFile() override {
        ofstream outFile("electronics.txt", ios::app | ios::binary);
        outFile.write((char*)this, sizeof(*this));
        outFile.close();
    }

    void loadFromFile() override {
        ifstream inFile("electronics.txt", ios::in | ios::binary);
        while (inFile.read((char*)this, sizeof(*this))) {
            displayProductDetails();
        }
        inFile.close();
    }

    void displayCategoryDetails() const override {
        cout << "Category: Electronics\n";
    }
};

// Purchase a product from any category
void purchaseProduct(const char* fileName, vector<pair<string, float>>& purchasedItems, float& totalBill) {
    cout << "Enter the Product ID to purchase: ";
    int id, quantity;
    cin >> id;

    fstream file(fileName, ios::in | ios::out | ios::binary);
    Product* temp;
    char buffer[sizeof(Product)];

    while (file.read(buffer, sizeof(Product))) {
        temp = reinterpret_cast<Product*>(buffer);
        if (temp->getProductID() == id) {
            cout << "Enter quantity to purchase: ";
            cin >> quantity;
            if (temp->getStockQuantity() >= quantity) {
                temp->setStockQuantity(temp->getStockQuantity() - quantity);
                file.seekp(-static_cast<int>(sizeof(Product)), ios::cur);
                file.write((char*)temp, sizeof(Product));

                // Add to purchased items
                purchasedItems.emplace_back(temp->getProductName(), temp->getProductPrice() * quantity);
                totalBill += temp->getProductPrice() * quantity;

                cout << "Purchase successful!\n";
            } else {
                cout << "Insufficient stock!\n";
            }
            file.close();
            return;
        }
    }

    file.close();
    cout << "Product not found!\n";
}

// Display menu options
int displayMenu() {
    int choice;
    cout << "\nBilling System Menu";
    cout << "\n1. Add New Product";
    cout << "\n2. View All Products";
    cout << "\n3. Purchase Product";
    cout << "\n4. Exit";
    cout << "\nEnter your choice: ";
    cin >> choice;
    return choice;
}

int main() {
    Product* product = nullptr;

    while (true) {
        system("cls");
        int choice = displayMenu();

        switch (choice) {
        case 1: {
            cout << "\nSelect Category: \n1. Grocery \n2. Clothing \n3. Electronics\n";
            int category;
            cin >> category;

            switch (category) {
            case 1:
                product = new Grocery();
                break;
            case 2:
                product = new Clothing();
                break;
            case 3:
                product = new Electronics();
                break;
            default:
                cout << "Invalid category!\n";
                continue;
            }

            product->inputProductDetails();
            product->saveToFile();
            delete product;
            break;
        }

        case 2: {
            Grocery grocery;
            Clothing clothing;
            Electronics electronics;

            cout << "\n--- Grocery Products ---\n";
            grocery.loadFromFile();

            cout << "\n--- Clothing Products ---\n";
            clothing.loadFromFile();

            cout << "\n--- Electronics Products ---\n";
            electronics.loadFromFile();
            break;
        }

        case 3: {
            vector<pair<string, float>> purchasedItems;
            float totalBill = 0.0;

            while (true) {
                cout << "\nSelect Category to Purchase From: \n1. Grocery \n2. Clothing \n3. Electronics \n4. Finish Purchasing\n";
                int category;
                cin >> category;

                if (category == 4) {
                    break;
                }

                switch (category) {
                case 1:
                    purchaseProduct("grocery.txt", purchasedItems, totalBill);
                    break;
                case 2:
                    purchaseProduct("clothing.txt", purchasedItems, totalBill);
                    break;
                case 3:
                    purchaseProduct("electronics.txt", purchasedItems, totalBill);
                    break;
                default:
                    cout << "Invalid category!\n";
                }
            }

            cout << "\n--- Bill Summary ---\n";
            for (const auto& item : purchasedItems) {
                cout << "Item: " << item.first << ", Amount: " << item.second << "\n";
            }
            cout << "Total Bill: " << totalBill << "\n";
            break;
        }

        case 4:
            cout << "Thank you for using the Billing System!\n";
            exit(0);

        default:
            cout << "Invalid choice!\n";
        }

        system("pause");
    }

}