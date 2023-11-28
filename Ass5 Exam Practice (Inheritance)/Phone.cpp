//Ruairi Mullally 22336002

#include "Phone.h"

Phone::Phone(std::string name, float price, float weight, unsigned int deliveryDays, bool isAndroid)
        : Article(name, price, weight, deliveryDays), isAndroid(isAndroid){
}

bool Phone::IsAndroid(){
    return this->isAndroid;
}

void Phone::PrintSummary() {
    cout << "Phone(name=" << this->GetName();
    cout << fixed << setprecision(2) << ",price=" << this->GetPrice();
    cout << fixed << setprecision(2) << ",weight=" << this->GetWeight();
    cout << fixed << setprecision(2) << ",shippingWeight=" << this->GetShippingWeight();
    cout << ",deliveryDays=" << this->GetDeliveryDays();
    cout << fixed << setprecision(2) << ",isAndroid=" << this->IsAndroid() << ")" << endl;
}
