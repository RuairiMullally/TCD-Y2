//Ruairi Mullally 22336002
#include "Monitor.h"

Monitor::Monitor(std::string name, float price, float weight, unsigned int deliveryDays, float size)
: Article(name, price, weight, deliveryDays), size(size){
}

float Monitor::GetSize() {
    return this->size;
}

float Monitor::GetShippingWeight() {
    return (this->GetWeight() + 2);
}

void Monitor::PrintSummary() {
    cout << "Monitor(name=" << this->GetName();
    cout << fixed << setprecision(2) << ",price=" << this->GetPrice();
    cout << fixed << setprecision(2) << ",weight=" << this->GetWeight();
    cout << fixed << setprecision(2) << ",shippingWeight=" << this->GetShippingWeight();
    cout << ",deliveryDays=" << this->GetDeliveryDays();
    cout << fixed << setprecision(2) << ",size=" << this->GetSize() << ")" << endl;
}