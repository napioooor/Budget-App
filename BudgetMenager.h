#ifndef BUDGETMENAGER_H
#define BUDGETMENAGER_H

#include <iostream>
#include <vector>
#include <windows.h>
#include <fstream>
#include <sstream>
#include <algorithm>

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

    void setLastExpenseId(int id);
    void setLastIncomeId(int id);
    int getLastIncomeId();
    int getLastExpenseId();
    int getLoggedInUserId();

    BudgetEntry getNewEntryData(int menuChoice);
    void loadBudgetEntriesFromFiles();
public:
    BudgetMenager(string incomeFileName, string expenseFileName, int id)
    : incomeFile(incomeFileName), expenseFile(expenseFileName), LOGGED_IN_USER_ID(id) {
        if (budgetEntries.empty() == true)
            loadBudgetEntriesFromFiles();
    };

    void addIncome();
    void addExpense();
    void outputThisMonthBudget();
    void outputLastMonthBudget();
    void outputChosenPeriodBudget();
};

#endif
