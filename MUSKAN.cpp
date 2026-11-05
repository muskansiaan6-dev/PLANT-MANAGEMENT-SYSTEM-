#include <iostream>
#include <string>
using namespace std;

class Plant {
    string name[10];
    int days[10];
    int n = 0;

public:
    void addPlant() {
        if (n == 10) {
            cout << "Plant list is full!\n";
            return;
        }

        cout << "Enter plant name: ";
        getline(cin, name[n]);

        if (name[n].empty()) {
            cout << "Plant name cannot be empty!\n";
            return;
        }

        cout << "Enter watering interval: ";
        cin >> days[n];
        cin.ignore(1000, '\n');

        if (days[n] <= 0) {
            cout << "Invalid interval! Enter a positive number.\n";
            return;
        }

        n++;
        cout << "Plant added successfully!\n";
    }

    void displayPlants() {
        if (n == 0) {
            cout << "No plants added!\n";
            return;
        }

        cout << "\n--- Plant Care List ---\n";

        for (int i = 0; i < n; i++) {
            cout << name[i] << " - Water every "
                 << days[i] << " days\n";
        }
    }
};

int main() {
    Plant p;
    int choice;

    do {
        cout << "\n1. Add Plant\n";
        cout << "2. Display Plants\n";
        cout << "3. Exit\n";
        cout << "Enter choice: ";

        cin >> choice;
        cin.ignore(1000, '\n');

        switch (choice) {
            case 1:
                p.addPlant();
                break;

            case 2:
                p.displayPlants();
                break;

            case 3:
                cout << "Thank you!\n";
                break;

            default:
                cout << "Invalid choice!\n";
        }

    } while (choice != 3);

    return 0;
}