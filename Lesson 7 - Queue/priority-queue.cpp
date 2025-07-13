#include <iostream>
using namespace std;

const int MAX = 100; // Max number of patients

struct Patient {
    string name;
    int priority;
};

class PriorityQueue {
private:
    Patient queue[MAX];
    int size;

public:
    PriorityQueue() {
        size = 0;
    }

    void insert(string name, int priority) {
        if (size == MAX) {
            cout << "Queue is full!\n";
            return;
        }

        // Create new patient
        Patient newPatient;
        newPatient.name = name;
        newPatient.priority = priority;

        // Insert in the correct position to keep highest priority first
        int i = size - 1;
        while (i >= 0 && queue[i].priority < priority) {
            queue[i + 1] = queue[i]; // Shift lower priority patients down
            i--;
        }

        queue[i + 1] = newPatient; // Insert new patient
        size++;
    }

    void serve() {
        if (size == 0) {
            cout << "No patients in queue.\n";
            return;
        }

        // Serve the patient with highest priority (front of the queue)
        cout << "Serving patient: " << queue[0].name << " (Priority: " << queue[0].priority << ")\n";

        // Shift remaining patients
        for (int i = 1; i < size; i++) {
            queue[i - 1] = queue[i];
        }
        size--;
    }

    void display() {
        if (size == 0) {
            cout << "Queue is empty.\n";
            return;
        }

        cout << "\nCurrent queue:\n";
        for (int i = 0; i < size; i++) {
            cout << i + 1 << ". " << queue[i].name << " (Priority: " << queue[i].priority << ")\n";
        }
    }
};

int main() {
    PriorityQueue pq;

    pq.insert("Anna", 2);
    pq.insert("Ben", 5);
    pq.insert("Charlie", 3);

    pq.display();

    pq.serve(); // Should serve Ben
    pq.serve(); // Should serve Charlie

    pq.display();

    return 0;
}