#include <iostream>
#include <limits>   // needed for numeric_limits
#include "menu.h"
using namespace std;

int selectMenu() {
    int choice;
    do {
        cout << "\n\033[36m^o^ apply which sorting algorithm?\033[0m\n";
        cout << "1 - bubble\n2 - insertion\n3 - selection\n4 - quick\n5 - merge\n";
        cout << "your choice: ";
        cin >> choice;

        if (cin.fail() || choice < 1 || choice > 5) {
            cout << "\033[31minvalid input! -.-\033[0m" << endl;
            cin.clear();
            cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
        }
    } while (choice < 1 || choice > 5);

    return choice;
}