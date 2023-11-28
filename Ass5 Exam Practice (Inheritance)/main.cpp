#include "Article.h"
#include "Monitor.h"
#include "Phone.h"
#include "ShoppingCart.h"
int main() {
    Article book("Douglas Adams: The Hitchhiker's Guide to the Galaxy", 8.99, 0.3, 1);
    Monitor monitor("Dell 19inch", 134.99, 1.3, 7, 19);
    Phone phone("Google Pixel 6", 699, 0.3, 3, true);
    ShoppingCart cart;
    cart.AddArticle(book);
    cart.AddArticle(monitor);
    cart.AddArticle(phone);
    cart.PrintSummary();
    return 0;
}