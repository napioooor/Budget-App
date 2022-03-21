#include "ExpenseFile.h"

void ExpenseFile::addExpenseToFile(BudgetEntry expense){
    CMarkup file;
    bool fileExists = file.Load(getFileName());
    string amount = to_string(expense.getAmount());
    amount.erase(amount.length() - 4, 4);

    if (!fileExists) {
        file.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        file.AddElem("Expenses");
    }

    file.FindElem();
    file.IntoElem();
    file.AddElem("Entry");
    file.IntoElem();
    file.AddElem("UserID", expense.getUserId());
    file.AddElem("EntryID", expense.getExpenseId());
    file.AddElem("Date", expense.getDate());
    file.AddElem("Item", expense.getItem());
    file.AddElem("Amount", amount);
    file.OutOfElem();

    file.Save(getFileName());
}

int ExpenseFile::loadEntriesFromFile(vector <BudgetEntry> &expenses, int loggedInUserId){
    BudgetEntry expense;
    CMarkup file;
    int lastId = 0;

    file.Load(getFileName());

    if(file.Load(getFileName()) == false)
        return lastId;

    file.FindElem();
    file.IntoElem();
    while(file.FindElem("Entry")) {
        file.IntoElem();
        file.FindElem("UserID");

        if(atoi( MCD_2PCSZ(file.GetData())) != loggedInUserId){
            file.FindElem("EntryID");
            lastId = atoi( MCD_2PCSZ(file.GetData()));
            file.OutOfElem();
            continue;
        }
        expense.setUserId(atoi( MCD_2PCSZ(file.GetData())));
        file.FindElem("EntryID");
        expense.setExpenseId(atoi( MCD_2PCSZ(file.GetData())));
        expense.setIncomeId(0);
        file.FindElem("Date");
        expense.setDate(atoi( MCD_2PCSZ(file.GetData())));
        file.FindElem("Item");
        expense.setItem(file.GetData());
        file.FindElem("Amount");
        expense.setAmount(atof( MCD_2PCSZ(file.GetData())));
        file.OutOfElem();
        expenses.push_back(expense);
    }

    if(expenses.empty() == true)
        return 0;
    else if(expenses[expenses.size() - 1].getExpenseId() > lastId)
        return expenses[expenses.size() - 1].getExpenseId();
    else
        return lastId;
}
