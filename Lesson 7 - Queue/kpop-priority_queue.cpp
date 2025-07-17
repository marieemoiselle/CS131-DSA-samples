#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

// storing member info via structs
struct Member {
    string name;
    double seconds;
};

void sortMembers(Member[], int);
char getYesNoInput(const string& prompt);

int main() {
    cout << "~ annyeong!! ^^ ~\n\n";

    string groupName, trackTitle;

    cout << "Enter group name: ";
    getline(cin, groupName);

    cout << "Enter track title: ";
    getline(cin, trackTitle);

    const int MAX = 100;
    Member members[MAX];
    int count = 0;

    while (true) {
        cout << "\nEnter " << groupName << " member: ";
        getline(cin, members[count].name);

        cout << "Enter number of seconds: ";
        while (!(cin >> members[count].seconds)) {
            cout << "Invalid input. Please enter a numeric value: ";
            cin.clear();
            cin.ignore(1000, '\n');
        }
        cin.ignore(); // clear input buffer

        count++;

        // in every entry, members are sorted
        sortMembers(members, count);

        // display the updated queue
        cout << "\n" << groupName << "'s \"" << trackTitle << "\" LINE DISTRIBUTION QUEUE\n";
        for (int i = 0; i < count; ++i) {
            cout << "[" << i + 1 << "] " << members[i].name << " - "
                 << fixed << setprecision(2) << members[i].seconds << "s\n";
        }

        // continue adding members
        char cont = getYesNoInput("\nContinue? (Y/N): ");
        if (cont == 'n') {
            char newGroup = getYesNoInput("\nNew group? (Y/N): ");
            if (newGroup == 'n') {
                cout << "\n~ gamsahabnida!! ^^ ~\n";
                break;
            } else {
                // Reset for new group
                cout << "\nEnter group name: ";
                getline(cin, groupName);

                cout << "Enter track title: ";
                getline(cin, trackTitle);

                count = 0; // reset members
            }
        }
    }

    return 0;
}

// sorting members in descending order (by seconds)
void sortMembers(Member members[], int count) {
    for (int i = 0; i < count - 1; ++i) {
        for (int j = i + 1; j < count; ++j) {
            if (members[j].seconds > members[i].seconds) {
                Member temp = members[i];
                members[i] = members[j];
                members[j] = temp;
            }
        }
    }
}

// for the yes/no questions
char getYesNoInput(const string& prompt) {
    char choice;
    while (true) {
        cout << prompt;
        cin >> choice;
        cin.ignore(); // clear buffer
        choice = tolower(choice);
        if (choice == 'y' || choice == 'n') {
            return choice;
        } else {
            cout << "Invalid input. Please enter Y or N.\n";
        }
    }
}