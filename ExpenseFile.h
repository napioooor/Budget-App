#ifndef EXPENSEFILE_H
#define EXPENSEFILE_H

#include <iostream>
#include <vector>
#include <fstream>
#include <cstdlib>

#include "BudgetEntry.h"
#include "SupportMethods.h"
#include "TextFile.h"
#include "Markup.h"

using namespace std;

class ExpenseFile : public TextFile{
public:
    ExpenseFile(string expenseFileName) : TextFile(expenseFileName) {};

};

#endif
