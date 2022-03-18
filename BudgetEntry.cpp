#include "BudgetEntry.h"

void BudgetEntry::setIncomeId(int newId) {
    incomeId = newId;
}

void BudgetEntry::setExpenseId(int newId) {
    expenseId = newId;
}

void BudgetEntry::setUserId(int newId) {
    userId = newId;
}

void BudgetEntry::setItem(string newItem) {
    item = newItem;
}

void BudgetEntry::setDate(int newDate) {
    date = newDate;
}

void BudgetEntry::setAmount(double newAmount) {
    amount = newAmount;
}

int BudgetEntry::getIncomeId() {
    return incomeId;
}

int BudgetEntry::getExpenseId() {
    return expenseId;
}

int BudgetEntry::getUserId() {
    return userId;
}

string BudgetEntry::getItem() {
    return item;
}

int BudgetEntry::getDate() {
    return date;
}

double BudgetEntry::getAmount() {
    return amount;
}
