//Ruairi Mullally 22336002

#include "Article.h"
Article::Article() = default;

Article::Article(std::string name, float price, float weight, unsigned int deliveryDays)
: deliveryDays(deliveryDays) {
    this->name = name.substr(0, 64);

    if(price > 0){
        this->price = price;
    }
    if(weight > 0){
        this->weight = weight;
    }
}

string Article::GetName() {
    return this->name;
}

float Article::GetPrice() {
    return this->price;
}

float Article::GetWeight() {
    return this->weight;
}

unsigned int Article::GetDeliveryDays() {
    return this->deliveryDays;
}

float Article::GetShippingWeight() {
    return (this->GetWeight() + 0.5);
}

void Article::PrintSummary() {
    cout << "Article(name=" << this->GetName();
    cout << fixed << setprecision(2) << ",price=" << this->GetPrice();
    cout << fixed << setprecision(2) << ",weight=" << this->GetWeight();
    cout << fixed << setprecision(2) << ",shippingWeight=" << this->GetShippingWeight();
    cout << ",deliveryDays=" << this->GetDeliveryDays() << ")" << endl;
}