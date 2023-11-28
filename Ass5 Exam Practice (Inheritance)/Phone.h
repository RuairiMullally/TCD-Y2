#ifndef PHONE_H
#define PHONE_H
#include "Article.h"

class Phone : public Article {
    bool isAndroid = true;
public:
    Phone (string name, float price, float weight, unsigned int deliveryDays, bool isAndroid);
    bool IsAndroid();
    void PrintSummary() override;
};
#endif //PHONE_H