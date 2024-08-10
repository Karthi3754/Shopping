#include <iostream>
#include <vector>
using namespace std;
class Product {
public:
Product(int id, string name, double price) : id(id), name(name), price(price) {}
int getId() const { return id; }
string getName() const { return name; }
double getPrice() const { return price; }
private:
int id;
string name;
double price;
};
class ShoppingCart {
public:
void addToCart(const Product& product, int quantity) {
cartItems.push_back(make_pair(product, quantity));
}
void displayCart() const {
double total = 0.0;
cout<< "Shopping Cart:\n";
cout<< "----------------------------------------\n";
for (const auto& item : cartItems) {
const Product& product = item.first;
int quantity = item.second;
cout<< "Product: " <<product.getName() << "\n";
cout<< "Quantity: " << quantity << "\n";
cout<< "Price per unit: $" <<product.getPrice() << "\n";
cout<< "Subtotal: $" <<product.getPrice() * quantity << "\n";
cout<< "----------------------------------------\n";
total += product.getPrice() * quantity;
}
cout<< "Total: $" << total << "\n";
}
private:
vector<pair<Product, int>>cartItems;
};
int main() {
// Create some sample products
Product laptop(1, "Laptop", 999.99);
Product smartphone(2, "Smartphone", 499.99);
Product headphones(3, "Headphones", 79.99);
// Create a shopping cart
ShoppingCart cart;
// Add products to the cart
cart.addToCart(laptop, 2);
cart.addToCart(smartphone, 1);
cart.addToCart(headphones, 3);
// Display the contents of the cart
cart.displayCart();
return 0;
}
