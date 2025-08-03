 #include <iostream>
 #include <string>
 using namespace std;
 class Product {
 public:
 string code;
 int totalItems;
 float price;
 Product() {}
 Product(string c, int t, float p) : code(c), totalItems(t), price(p) {}
 operator float() const {
 return totalItems * price;
 }
 };
 void checkInventory(Product* inventory, int size, string code) {
 for (int i = 0; i < size; i++) {
 if (inventory[i].code == code) {
 float totalPrice = inventory[i];
 cout << "Product found: Total price = " << totalPrice << endl;
 return;
 }
 }
 cout << "Product not found in the inventory." << endl;
 return;
 }
 int main() {
 int n;
 cout << "Enter the number of products in the inventory: ";
 cin >> n;
 Product* inventory = new Product[n];
 for (int i = 0; i < n; i++) {
string code;
 int totalItems;
 float price;
 cout << "Enter the code for product " << i + 1 << ": ";
 cin >> code;
 cout << "Enter the total number of items for product " << i + 1 << ": ";
 cin >> totalItems;
 cout << "Enter the price for product " << i + 1 << ": ";
 cin >> price;
 inventory[i] = Product(code, totalItems, price);
 }
 string searchCode;
 cout << "Enter the product code to search: ";
 cin >> searchCode;
 checkInventory(inventory, n, searchCode);
 delete[] inventory;
 return 0;
 }