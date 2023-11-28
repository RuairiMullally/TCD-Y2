#ifndef ARTICLE_H
#define ARTICLE_H
#include<string>
#include <iostream>
#include <iomanip>

using namespace std;

class Article {
protected:
    string name = "(unnamed)";
    float price = 0.0; // price in Euro
    float weight = 0.0; // weight in kg
    unsigned int deliveryDays = 14; // days to deliver
public:
    Article();
    Article(string name, float price, float weight, unsigned int deliveryDays);
    string GetName();
    float GetPrice();
    float GetWeight();
    unsigned int GetDeliveryDays();
// virtual needed to ensure specialised variants of this method are not hidden
    virtual float GetShippingWeight();
    virtual void PrintSummary();
};
#endif //ARTICLE_H
