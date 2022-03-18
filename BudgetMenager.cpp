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

    cout << endl << "income: " << lastIncomeId << " expense: " << lastExpenseId << endl;
    system("pause");

    budgetEntries.insert(budgetEntries.begin(), incomes.begin(), incomes.end());
    budgetEntries.insert(budgetEntries.end(), expenses.begin(), expenses.end());

    sort(budgetEntries.begin(), budgetEntries.end(), [](BudgetEntry a, BudgetEntry b) {
        return a.getDate() < b.getDate();
    });
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

        switch(choice) {
        case 't':
            date = SupportMethods::properCurrentDate();

            budgetEntry.setDate(SupportMethods::convertDateFromStringToInt(date));

            break;
        case 'n':
            cout << "Podaj date w formacie RRRR-MM-DD: " << endl;
            date = SupportMethods::inputLine();

            if(SupportMethods::isDateCorrect(date) == false){
                cout << "Podano niepoprawna date. Sproboj ponownie." << endl;
                continue;
            }

            budgetEntry.setDate(SupportMethods::convertDateFromStringToInt(date));

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

void BudgetMenager::outputThisMonthBudget() {}

void BudgetMenager::outputLastMonthBudget() {}

void BudgetMenager::outputChosenPeriodBudget() {}
