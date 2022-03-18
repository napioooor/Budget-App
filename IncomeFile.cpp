#include "IncomeFile.h"

void IncomeFile::addIncomeToFile(BudgetEntry income){
    CMarkup file;
    bool fileExists = file.Load(getFileName());

    if (!fileExists) {
        file.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        file.AddElem("Incomes");
    }

    file.FindElem();
    file.IntoElem();
    file.AddElem("Entry");
    file.IntoElem();
    file.AddElem("UserID", income.getUserId());
    file.AddElem("EntryID", income.getIncomeId());
    file.AddElem("Date", income.getDate());
    file.AddElem("Item", income.getItem());
    file.AddElem("Amount", to_string(income.getAmount()));
    file.OutOfElem();

    file.Save(getFileName());
}

int IncomeFile::loadEntriesFromFile(vector <BudgetEntry> &incomes, int loggedInUserId){
    BudgetEntry income;
    CMarkup file;

    file.Load(getFileName());
    file.FindElem();
    file.IntoElem();
    while(file.FindElem("Entry")) {
        file.IntoElem();
        file.FindElem("UserID");

        if(atoi( MCD_2PCSZ(file.GetData())) != loggedInUserId){
            file.OutOfElem();
            continue;
        }
        income.setUserId(atoi( MCD_2PCSZ(file.GetData())));
        file.FindElem("EntryID");
        income.setExpenseId(0);
        income.setIncomeId(atoi( MCD_2PCSZ(file.GetData())));
        file.FindElem("Date");
        income.setDate(atoi( MCD_2PCSZ(file.GetData())));
        file.FindElem("Item");
        income.setItem(file.GetData());
        file.FindElem("Amount");
        income.setAmount(atof( MCD_2PCSZ(file.GetData())));
        file.OutOfElem();
        incomes.push_back(income);
    }

    if(incomes.empty() == true)
        return 0;
    else
        return incomes[incomes.size() - 1].getIncomeId();
}
