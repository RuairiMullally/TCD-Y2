#ifndef MONITOR_H
#define MONITOR_H
#include "Article.h"

class Monitor : public Article {
    float size = 0.0; // diagonal of the display in inch
public:
    Monitor(string name, float price, float weight, unsigned int deliveryDays, float size);
    float GetSize();
    float GetShippingWeight() override;
    void PrintSummary() override;
};
#endif //MONITOR_H