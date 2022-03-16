#ifndef BUDGETMENAGER_H
#define BUDGETMENAGER_H

#include <iostream>
#include <vector>
#include <windows.h>
#include <fstream>
#include <sstream>

#include "BudgetEntry.h"
#include "IncomeFile.h"
#include "ExpenseFile.h"

using namespace std;

class BudgetMenager{
    IncomeFile incomeFile;
    ExpenseFile expenseFile;
    const int LOGGED_IN_USER_ID;
    int lastExpenseId, lastIncomeId;

    vector <BudgetEntry> budgetEntries;

public:
    BudgetMenager(string incomeFileName, string expenseFileName, int id)
    : incomeFile(incomeFileName), expenseFile(expenseFileName), LOGGED_IN_USER_ID(id) {};

    void addIncome();
    void addExpense();
    void outputThisMonthBudget();
    void outputLastMonthBudget();
    void outputChosenPeriodBudget();
};

#endif
