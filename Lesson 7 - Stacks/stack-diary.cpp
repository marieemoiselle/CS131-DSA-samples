#include <iostream>
#include <stack>
#include <ctime>
#include <fstream>
#include <vector>
using namespace std;

// structure for a diary entry
struct Entry {
    string datetime;
    string message;
};

// function to get current date and time
string getCurrentDateTime() {
    time_t now = time(0);
    tm *ltm = localtime(&now);

    char buffer[30];
    strftime(buffer, sizeof(buffer), "%Y-%m-%d %I:%M%p", ltm);

    return string(buffer);
}

// load entries from file to stack
void loadFromFile(stack<Entry> &diary) {
    ifstream file("diary.txt");
    
    string line;

    while (getline(file, line)) {
        int pos = line.find('|');

        if (pos != string::npos) {
            Entry e;

            // to handle spaces around '|'
            string left = line.substr(0, pos);
            string right = line.substr(pos + 1);

            // remove trailing space (before |)
            if (!left.empty() && left.back() == ' ')
                left.pop_back();

            // remove leading space (after |)
            if (!right.empty() && right.front() == ' ')
                right.erase(0, 1);

            e.datetime = left;
            e.message = right;

            diary.push(e);
        }
    }

    file.close();
}

// save entries from stack to file
void saveToFile(stack<Entry> diary) {
    vector<Entry> temp;

    while (!diary.empty()) {
        temp.push_back(diary.top());
        diary.pop();
    }

    // overwrite file (not append)
    ofstream file("diary.txt");

    for (int i = temp.size() - 1; i >= 0; i--) {
        file << temp[i].datetime << " | " << temp[i].message << endl;
    }

    file.close();
}

// function to display all entries
void viewEntries(stack<Entry> s) {
    if (s.empty()) {
        cout << "\n[ no diary entries found ]\n";
        return;
    }

    cout << "\n\033[1;35m[ +_+ ~ your diary entries ~ ]\033[0m" << endl;

    int index = 1;

    // since stack is LIFO, we copy it to display
    while (!s.empty()) {
        Entry e = s.top();
        cout << "[" << index << "] " << e.datetime << " - " << e.message << endl;
        s.pop();
        index++;
    }
}

int main() {
    stack<Entry> diary;
    int choice;
    string message;

    loadFromFile(diary);

    do {
    cout << "\n\033[1;33m ^^, [ ~ main menu ~]\033[0m\n";
    cout << "1. Add Entry\n";
    cout << "2. View Entries\n";
    cout << "3. Delete Latest Entry\n";
    cout << "4. Exit\n";
    cout << "Enter choice: ";

    cin >> choice;

    // fix: handle invalid input
    if (cin.fail()) {
        cin.clear(); // reset error flag
        cin.ignore(1000, '\n'); // discard invalid input
        cout << "\n\033[1;31m [ invalid input! ]\033[0m\n";
        continue; // restart loop
    }

    cin.ignore(); // clear newline

    switch (choice) {
        case 1: {
            cout << "Your entry: ";
            getline(cin, message);

            Entry newEntry;
            newEntry.datetime = getCurrentDateTime();
            newEntry.message = message;

            diary.push(newEntry);
            saveToFile(diary);

            cout << "\n\033[1;32m[ successfully added! ]\033[0m\n";
            
            viewEntries(diary);
            break;
        }

        case 2:
            viewEntries(diary);
            break;

        case 3:
            if (diary.empty()) {
                cout << "\n\033[1;31m [ no entries to delete! ]\033[0m\n";
            } else {
                diary.pop();
                saveToFile(diary); // VERY IMPORTANT
                cout << "\n\033[1;32m[ latest entry deleted! ]\033[0m\n";
            }
            break;

        case 4:
            cout << "\n\033[1;36m[ exiting diary... >.< ]\033[0m\n";
            break;

        default:
            cout << "\n\033[1;31m [ invalid input! ]\033[0m\n";;
    }

} while (choice != 4);

    return 0;
}