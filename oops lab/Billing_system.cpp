#include <bits/stdc++.h>
#include <windows.h>
#include <fstream>
using namespace std;

// Product class
class Product {

    int productID;
    char productName[51];
    float productPrice;
    int stockQuantity;

public:

    // Default constructor
    Product() {
        productID = 0;
        strcpy(productName, "No name");
        productPrice = 0.0;
        stockQuantity = 0;
    }

    // Function to input product details
    void inputProductDetails() {
        cout << "Enter product ID, name, price, and quantity: ";
        
        while(true){

         cin >> productID;

         if (cin.fail()) { // Check for invalid input
            cin.clear(); // Clear the error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
            cout << "Invalid input! Please enter a number in integer\n";
         } 
         else   // Return valid input
         {
           break;
         }
        }
        cin.ignore();
        cin.getline(productName, 50);
        cin >> productPrice >> stockQuantity;
    }

    // Function to display product details
    void displayProductDetails() const {
        cout << "\nProduct ID: " << productID
             << "\nName: " << productName
             << "\nPrice: " << productPrice
             << "\nStock Quantity: " << stockQuantity << "\n";
    }

    // function to get  product name
    const char* getProductName() const { 
        return productName;
    }

    // function to get product quantity
    int getStockQuantity() const { 
        return stockQuantity; 
    }

    // function to get product ID
    int getProductID() const { 
        return productID; 
    }

    // function to set stock quantity 
    void setStockQuantity(int quantity) { 
        stockQuantity = quantity; 
    }

    bool DoesProductExists(); //to see if a the given productid is already existing

    // File operations
    void addNewProduct();
    void displayAllProducts();
    void modifyProduct(int id);
    void removeProduct(int id);
    void purchaseProduct();
    
};

// function to see if a the given productid is already existing
bool Product::DoesProductExists() {
    
    ifstream inFile("products.txt", ios::in | ios::binary);
    if (!inFile) {
        return false;  
    }

    Product tempProduct;
    while (inFile.read((char*)&tempProduct, sizeof(tempProduct))) {
        if (tempProduct.productID == this->productID) {
            inFile.close();
            return true;
        }
    }

    inFile.close();
    return false;
}

//Function to add new product
void Product::addNewProduct() {
    ofstream outFile("products.txt", ios::app | ios::binary);
    if (!outFile) {
        cout << "Error opening file!\n";
        return;
    }

    inputProductDetails();

    while (DoesProductExists()) {
        cout << "Product ID already exists. Enter a new Product ID: ";
        int newID;
        cin >> newID;
        productID = newID;
    }

    outFile.write((char*)this, sizeof(*this));
    outFile.close();

    cout << "Product added successfully!\n";
}

// Function to view all products...
void Product::displayAllProducts() {
    ifstream inFile("products.txt", ios::in | ios::binary);
    if (!inFile) {
        cout << "No products found!\n";
        return;
    }
    
    Product p;
    while (inFile.read((char*)&p, sizeof(*this))) {
        p.displayProductDetails();
    }
    inFile.close();
}

// Function to update product details...
void Product::modifyProduct(int id) {
    fstream file("products.txt", ios::in | ios::out | ios::binary);
    if (!file) {
        cout << "Error opening file!\n";
        return;
    }

    bool found = false;
    while (file.read((char*)this, sizeof(*this))) {
        if (productID == id) {
            cout << "Current details of the product:\n";
            displayProductDetails();
            cout << "Enter new details for the product:\n";
            inputProductDetails();
            file.seekp(file.tellp() - sizeof(*this));
            file.write((char*)this, sizeof(*this));
            cout << "Product updated successfully!\n";
            found = true;
            break;
        }
    }

    if (!found)
        cout<< "Product with ID "<<id<< " not found!\n";

    file.close();
}

// Function to delete a product...
void Product::removeProduct(int id) {
    ifstream inFile("products.txt", ios::in | ios::binary);
    ofstream outFile("temp.txt", ios::out | ios::binary);
    if (!inFile || !outFile) {
        cout << "Error opening file!\n";
        return;
    }

    bool found = false;
    while (inFile.read((char*)this, sizeof(Product))) {
        if (productID == id) {
            found = true;
        } else {
            outFile.write((char*)this, sizeof(*this));
        }
    }

    inFile.close();
    outFile.close();
    remove("products.txt");
    rename("temp.txt", "products.txt");

    if (found)
        cout << "Product deleted successfully!\n";
    else
        cout << "Product with ID " << id << " not found!\n";
}

// Function to handle product purchase
void Product::purchaseProduct() {
    ifstream inFile("products.txt", ios::in | ios::binary);
    ofstream outFile("temp.txt", ios::out | ios::binary);
    if (!inFile || !outFile) {
        cout << "Error opening file!\n";
        return;
    }

    int id, quantityToPurchase;
    bool found = false;
    float totalCost = 0;

    cout << "Enter the product ID to purchase: ";
    cin >> id;
    cout << "Enter the quantity to buy: ";
    cin >> quantityToPurchase;

    while (inFile.read((char*)this, sizeof(*this))) {
        if (productID == id) {
            found = true;
            if (stockQuantity >= quantityToPurchase) {
                totalCost = productPrice * quantityToPurchase;
                stockQuantity -= quantityToPurchase;

                cout<<" Item_id | Rate | Quantity | item_name"<<endl;
                cout<<this->productID<<"\t "<<this->productPrice<<"\t "<<this->stockQuantity<<"\t "<<this->productName<<endl<<endl;
                cout << "Purchase successful! Total cost: Rs "<<totalCost<<"\n";
            } else {
                cout << "Insufficient stock available!\n";
            }
        }
        outFile.write((char*)this, sizeof(*this));
    }

    if (!found) {
        cout << "Product not found!\n";
    }

    inFile.close();
    outFile.close();
    remove("products.txt");
    rename("temp.txt", "products.txt");
}

int displayMenu() {  //menu function

    int choice; 

    while (true) {

        cout << "\nBilling System Menu";
        cout << "\n1. Add New Product (Seller)";
        cout << "\n2. View All Products (All)";
        cout << "\n3. Update Product Details (Seller)";
        cout << "\n4. Delete Product (Seller)";
        cout << "\n5. Purchase Product (Buyer)";
        cout << "\n6. Exit";
        cout << "\n\nEnter your choice: ";

        cin >> choice;  

        if (cin.fail()) { // Check for invalid input
            cin.clear(); // Clear the error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
            cout << "Invalid input! Please enter a number between 1 and 6.\n";
            Sleep(2000);
            system("cls");
        } 
        else if (choice < 1 || choice > 6)   // Check for valid range
        { 
            cout << "Invalid choice! Please enter a number between 1 and 6.\n";
            Sleep(2000);
            system("cls");
        } 
        else   // Return valid input
        {
            return choice; 
        }

    }
}

int main() {
    Product product;
    int id;

    while (true) 
    {
        system("cls");
        switch (displayMenu()) {
        case 1:
            product.addNewProduct();
            break;
        case 2:
            product.displayAllProducts();
            break;
        case 3:
            cout << "Enter the product ID to update: ";
            cin >> id;
            product.modifyProduct(id);
            break;
        case 4:
            cout << "Enter the product ID to delete: ";
            cin >> id;
            product.removeProduct(id);
            break;
        case 5:
            product.purchaseProduct();
            break;
        case 6:
            cout << "Thank you for using the Billing System!\n";
            exit(0);
        
        }
        system("pause");  
    }
    return 0;
}
