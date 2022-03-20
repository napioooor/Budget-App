#ifndef INCOMEFILE_H
#define INCOMEFILE_H

#include <iostream>
#include <vector>
#include <fstream>
#include <cstdlib>
#include <string.h>

#include "BudgetEntry.h"
#include "SupportMethods.h"
#include "TextFile.h"
#include "Markup.h"

using namespace std;

class IncomeFile : public TextFile{
public:
    IncomeFile(string incomeFileName) : TextFile(incomeFileName) {};
    void addIncomeToFile(BudgetEntry income);
    int loadEntriesFromFile(vector <BudgetEntry> &incomes, int loggedInUserId);
};

#endif
