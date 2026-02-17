#include <iostream>
#include <string>
using namespace std;

struct Person {
    int id;
    string name;
};

int main() {

    Person* person = new Person;

    if (person != nullptr) {
        person->id = 1;
        person->name = "Do Ra-mi";

        cout << "ID: " << person->id << endl;
        cout << "Name: " << person->name << endl;

        delete person;
    }

    return 0;
}