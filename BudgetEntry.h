#ifndef BUDGETENTRY_H
#define BUDGETENTRY_H

#include <iostream>

using namespace std;

class BudgetEntry{
    int incomeId, expenseId, userId;
    string item;
    unsigned int date;
    double amount;

public:
    void setIncomeId(int newId);
    void setExpenseId(int newId);
    void setUserId(int newId);
    void setItem(string newItem);
    void setDate(int newDate);
    void setAmount(double newAmount);

    int getIncomeId();
    int getExpenseId();
    int getUserId();
    string getItem();
    int getDate();
    double getAmount();
};

#endif
