//
// Created by ruair on 28/11/2023.
//

#ifndef SHOPPINGCART_H
#define SHOPPINGCART_H

#include "Article.h"
#include <iostream>
#include <iomanip>

class ShoppingCart {
    unsigned int numArticles = 0;
    Article * articles[10]{}; // {} initialises the array with null pointers
public:
    void AddArticle(Article &newArticle);
    Article * GetArticle(unsigned int index);
    unsigned int GetNumArticles();
    unsigned int GetDeliveryDays(); // first day all articles deliverable
    double GetTotalPrice();
    double GetTotalShippingWeight();
    void PrintSummary();
};
#endif //SHOPPINGCART_H