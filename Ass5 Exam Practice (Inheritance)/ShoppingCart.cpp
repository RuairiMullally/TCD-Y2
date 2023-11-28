//Ruairi Mullally 22336002

#include "ShoppingCart.h"

void ShoppingCart::AddArticle(Article &newArticle) {
    if(this->numArticles < 10){

        this->articles[numArticles] = &newArticle;
        this->numArticles++;
    }
}

Article* ShoppingCart::GetArticle(unsigned int index) {
    if(index > numArticles -1){
        return nullptr;
    }
    return this->articles[index];
}

unsigned int ShoppingCart::GetNumArticles() {
    return numArticles;
}

unsigned int ShoppingCart::GetDeliveryDays(){
    unsigned int max = 0;
    for(int i = 0; i < numArticles; i++){
        unsigned int days = articles[i]->GetDeliveryDays();
        if(days > max){
            max = days;
        }
    }
    return max;
}

double ShoppingCart::GetTotalPrice() {
    double total = 0.0;
    for(int i = 0; i < numArticles; i++){
        double price = articles[i]->GetPrice();
        total += price;
    }
    return total;
}

double ShoppingCart::GetTotalShippingWeight() {
    double total = 0.0;
    for(int i = 0; i < numArticles; i++){
        double weight = articles[i]->GetShippingWeight();
        total += weight;
    }
    return total;
}

void ShoppingCart::PrintSummary() {
    int index = 1;
    //cout << numArticles;
    cout << "ShoppingCart(Articles=[" << endl;

    for(int i = 0; i < numArticles; i++){
        cout << "#" << i+1 << " ";
        articles[i]->PrintSummary();

    }
    cout << "]," << endl << "deliveryDays=" << this->GetDeliveryDays();
    cout << ", totalPrice=" << this->GetTotalPrice() << ", weight=" << this->GetTotalShippingWeight() << ")" << endl;
}
