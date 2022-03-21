#include "BudgetMenager.h"

void BudgetMenager::setLastExpenseId(int id) {
    lastExpenseId = id;
}

void BudgetMenager::setLastIncomeId(int id) {
    lastIncomeId = id;
}

int BudgetMenager::getLastIncomeId() {
    return lastIncomeId;
}

int BudgetMenager::getLastExpenseId() {
    return lastExpenseId;
}

int BudgetMenager::getLoggedInUserId() {
    return LOGGED_IN_USER_ID;
}

void BudgetMenager::loadBudgetEntriesFromFiles(){
    vector <BudgetEntry> incomes;
    vector <BudgetEntry> expenses;

    setLastIncomeId(incomeFile.loadEntriesFromFile(incomes, getLoggedInUserId()));
    setLastExpenseId(expenseFile.loadEntriesFromFile(expenses, getLoggedInUserId()));

    budgetEntries.insert(budgetEntries.begin(), incomes.begin(), incomes.end());
    budgetEntries.insert(budgetEntries.end(), expenses.begin(), expenses.end());

    sortBudgetEntries();
}

void BudgetMenager::sortBudgetEntries(){
    sort(budgetEntries.begin(), budgetEntries.end(), [](BudgetEntry a, BudgetEntry b) {
        return a.getDate() < b.getDate();});
}

void BudgetMenager::addIncome() {
    BudgetEntry budgetEntry;

    system("cls");
    cout << " >>> DODAWANIE NOWEGO WPISU <<<" << endl << endl;
    budgetEntry = getNewEntryData(0);

    budgetEntries.push_back(budgetEntry);

    incomeFile.addIncomeToFile(budgetEntry);

    setLastIncomeId(++lastIncomeId);

    cout << endl << "Wpis dodano pomyslnie" << endl << endl;
    system("pause");
}

void BudgetMenager::addExpense() {
    BudgetEntry budgetEntry;

    system("cls");
    cout << " >>> DODAWANIE NOWEGO WPISU <<<" << endl << endl;
    budgetEntry = getNewEntryData(1);

    budgetEntries.push_back(budgetEntry);

    expenseFile.addExpenseToFile(budgetEntry);

    setLastExpenseId(++lastExpenseId);

    cout << endl << "Wpis dodano pomyslnie" << endl << endl;
    system("pause");
}

BudgetEntry BudgetMenager::getNewEntryData(int menuChoice) {
    BudgetEntry budgetEntry;
    string amount, date;

    budgetEntry.setUserId(LOGGED_IN_USER_ID);

    if(menuChoice == 0) {
        budgetEntry.setIncomeId(++lastIncomeId);
        budgetEntry.setExpenseId(0);
    }

    if(menuChoice == 1) {
        budgetEntry.setIncomeId(0);
        budgetEntry.setExpenseId(++lastExpenseId);
    }

    for(;;) {

        cout << "Czy chcialbys dodac wpis z obecna data? [T/N]" << endl;
        char choice = SupportMethods::inputChar();

        choice = toupper(choice);

        switch(choice) {
        case 'T':
            date = dateMenager.properCurrentDate();

            budgetEntry.setDate(dateMenager.convertDateFromStringToInt(date));

            break;
        case 'N':
            cout << "Podaj date w formacie RRRR-MM-DD: " << endl;
            date = SupportMethods::inputLine();

            if(dateMenager.isDateCorrect(date) == false){
                cout << "Podano niepoprawna date. Sproboj ponownie." << endl;
                continue;
            }

            budgetEntry.setDate(dateMenager.convertDateFromStringToInt(date));

            break;
        default:
            cout << "Niepoprawny znak. Sproboj ponownie." << endl;
            continue;
        }

        cout << "Nazwa wpisu: " << endl;
        budgetEntry.setItem(SupportMethods::inputLine());

        cout << "Podaj kwote: " << endl;
        amount = SupportMethods::inputLine();
        budgetEntry.setAmount(SupportMethods::convertStringToDouble(SupportMethods::convertCommaToPoint(amount)));

        return budgetEntry;
    }
}

void BudgetMenager::outputBudget(int date1, int date2){
    double sumIncomes = 0, sumExpenses = 0, difference = 0;
    sortBudgetEntries();
    string date;

    cout.precision(2);
    cout.setf(ios::showpoint);
    cout.setf(ios::fixed);

    cout << endl << "PRZYCHODY:" << endl;
    cout << "----------------------" << endl;

    for(int i = 0; i < budgetEntries.size(); i++){
        if(budgetEntries[i].getDate() >= date1 && budgetEntries[i].getDate() <= date2 && budgetEntries[i].getExpenseId() == 0){
            date = dateMenager.convertIntDateToString(budgetEntries[i].getDate());
            cout << "+" << budgetEntries[i].getAmount() << " - " << budgetEntries[i].getItem() << " (" << date << ")" << endl;
            sumIncomes += budgetEntries[i].getAmount();
        }
    }


    cout << "----------------------" << endl << endl;
    cout << "WYDATKI:" << endl;
    cout << "----------------------" << endl;

    for(int i = 0; i < budgetEntries.size(); i++){
        if(budgetEntries[i].getDate() >= date1 && budgetEntries[i].getDate() <= date2 && budgetEntries[i].getIncomeId() == 0){
            date = dateMenager.convertIntDateToString(budgetEntries[i].getDate());
            cout << "-" << budgetEntries[i].getAmount() << " - " << budgetEntries[i].getItem() << " (" << date << ")" << endl;
            sumExpenses -= budgetEntries[i].getAmount();
        }
    }

    cout << "----------------------" << endl;

    difference = sumIncomes + sumExpenses;

    if(sumIncomes == 0 && sumExpenses == 0)
        cout << "Brak wpisow w tym okresie. Dadaj je z pozycji menu." << endl;
    else {
    cout << endl << "Suma przychodow: " << sumIncomes << endl;
    cout << "Suma wydatkow: " << sumExpenses << endl;
    cout << "Bilans: " << difference << endl;
    }
}

void BudgetMenager::outputThisMonthBudget() {
    int date;

    system("cls");
    cout << "BUDZET TEGO MIESIACA:" << endl << endl;

    date = dateMenager.convertDateFromStringToInt(dateMenager.properCurrentDate());

    date = date / 100 * 100;

    outputBudget(date, date + 100);

    system("pause");
}

void BudgetMenager::outputLastMonthBudget() {
    int date;

    system("cls");
    cout << "BUDZET ZESZLEGO MIESIACA:" << endl << endl;

    date = dateMenager.convertDateFromStringToInt(dateMenager.properCurrentDate());

    date = date / 100 * 100;

    outputBudget(date - 100, date);

    system("pause");
}

void BudgetMenager::outputChosenPeriodBudget() {
    int date1, date2;
    string sdate1, sdate2;

    system("cls");
    cout << "Podaj od jakiej daty ma byc wyswietlony bilans: (RRRR-MM-DD)" << endl;
    sdate1 = SupportMethods::inputLine();

    if(dateMenager.isDateCorrect(sdate1) == false) {
        cout << "Podano niepoprawna date. Sproboj ponownie." << endl;
        system("pause");
        return;
    }
    date1 = dateMenager.convertDateFromStringToInt(sdate1);

    cout << "Podaj do jakiej daty ma byc wyswietlony bilans: (RRRR-MM-DD)" << endl;
    sdate2 = SupportMethods::inputLine();

    if(dateMenager.isDateCorrect(sdate2) == false) {
        cout << "Podano niepoprawna date. Sproboj ponownie." << endl;
        system("pause");
        return;
    }
    date2 = dateMenager.convertDateFromStringToInt(sdate2);

    if(date1 > date2) {
        cout << "Pierwsza data jest wieksza od drugiej. Sprobuj ponownie." << endl;
        system("pause");
             return;
    }

    system("cls");

    outputBudget(date1, date2);

    system("pause");
}
