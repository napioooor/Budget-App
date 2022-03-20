#include "Menu.h"

void Menu::runMenu(UserMenager userMenager) {
    char choice;

    while (true) {
        if (userMenager.getLoggedInUserId() == 0) {
            choice = pickOptionFromMainMenu();

            switch (choice) {
            case '1':
                userMenager.registerNewUser();
                break;
            case '2':
                userMenager.setLoggedInUserId(userMenager.userLogIn());
                break;
            case '9':
                exit(0);
                break;
            default:
                cout << endl << "Nie ma takiej opcji w menu." << endl << endl;
                system("pause");
                break;
            }
        } else {
            BudgetMenager budgetMenager("incomes.xml", "expenses.xml", userMenager.getLoggedInUserId());

            choice = pickOptionFromUserMenu();

            switch (choice) {
            case '1':
                budgetMenager.addIncome();
                break;
            case '2':
                budgetMenager.addExpense();
                break;
            case '3':
                budgetMenager.outputThisMonthBudget();
                break;
            case '4':
                budgetMenager.outputLastMonthBudget();
                break;
            case '5':
                budgetMenager.outputChosenPeriodBudget();
                break;
            case '7':
                userMenager.changeLoggedInUsersPassword();
                break;
            case '8':
                userMenager.setLoggedInUserId(0);
                break;
            }
        }
    }
}

char Menu::pickOptionFromMainMenu() {
    char choice;

    system("cls");
    cout << "    >>> MENU  GLOWNE <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "1. Rejestracja" << endl;
    cout << "2. Logowanie" << endl;
    cout << "9. Koniec programu" << endl;
    cout << "---------------------------" << endl;
    cout << "Twoj wybor: ";
    choice = SupportMethods::inputChar();

    return choice;
}

char Menu::pickOptionFromUserMenu() {
    char choice;

    system("cls");
    cout << " >>> MENU UZYTKOWNIKA <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "1. Dodaj przychod" << endl;
    cout << "2. Dodaj wydatek" << endl;
    cout << "3. Bilans z bierzacego miesiaca" << endl;
    cout << "4. Bilans z poprzedniego miesiaca" << endl;
    cout << "5. Bilans z wybranego okresu" << endl;
    cout << "---------------------------" << endl;
    cout << "7. Zmien haslo" << endl;
    cout << "8. Wyloguj sie" << endl;
    cout << "---------------------------" << endl;
    cout << "Twoj wybor: ";
    choice = SupportMethods::inputChar();

    return choice;
}
