#include "Menu.h"

void Menu::runMenu(UserMenager userMenager){
    char choice;

    while (true)
    {
        if (userMenager.getLoggedInUserId() == 0)
        {
            choice = pickOptionFromMainMenu();

            switch (choice)
            {
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
        }
        else
        {
            //AdresatMenedzer adresatMenedzer("Adresaci.txt", userMenager.pobierzIdZalogowanegoUzytkownika());

            choice = pickOptionFromUserMenu();

            switch (choice)
            {
            /*case '1':
                adresatMenedzer.dodajAdresata();
                break;
            case '2':
                adresatMenedzer.wyszukajAdresatowPoImieniu();
                break;
            case '3':
                adresatMenedzer.wyszukajAdresatowPoNazwisku();
                break;
            case '4':
                adresatMenedzer.wyswietlWszystkichAdresatow();
                break;
            case '5':
                adresatMenedzer.usunAdresata();
                break;
            case '6':
                adresatMenedzer.edytujAdresata();
                break;*/
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
    cout << "1. Dodaj adresata" << endl;
    cout << "2. Wyszukaj po imieniu" << endl;
    cout << "3. Wyszukaj po nazwisku" << endl;
    cout << "4. Wyswietl adresatow" << endl;
    cout << "5. Usun adresata" << endl;
    cout << "6. Edytuj adresata" << endl;
    cout << "---------------------------" << endl;
    cout << "7. Zmien haslo" << endl;
    cout << "8. Wyloguj sie" << endl;
    cout << "---------------------------" << endl;
    cout << "Twoj wybor: ";
    choice = SupportMethods::inputChar();

    return choice;
}
