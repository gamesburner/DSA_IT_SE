#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct Student {
    int rollNo;
    string name;
    string division;
    string address;
};

void createFile() {
    ofstream outFile("students.dat", ios::binary | ios::app);
    if (!outFile) {
        cout << "Error opening file!" << endl;
        return;
    }

    int n;
    cout << "Enter number of students: ";
    cin >> n;
    cin.ignore();  

    Student student;

    for (int i = 0; i < n; i++) {
        cout << "\nEnter details for student " << i + 1 << endl;
        cout << "Roll No: ";
        cin >> student.rollNo;
        cin.ignore(); 
        cout << "Name: ";
        getline(cin, student.name);
        cout << "Division: ";
        getline(cin, student.division);
        cout << "Address: ";
        getline(cin, student.address);

        outFile.write(reinterpret_cast<char*>(&student), sizeof(student));
    }

    outFile.close();
    cout << "Student data saved successfully!" << endl;
}

void displayFile() {
    ifstream inFile("students.dat", ios::binary);
    if (!inFile) {
        cout << "Error opening file!" << endl;
        return;
    }

    Student student;
    cout << "\nDisplaying student data from the file:\n";
    while (inFile.read(reinterpret_cast<char*>(&student), sizeof(student))) {
        cout << "\nRoll No: " << student.rollNo << endl;
        cout << "Name: " << student.name << endl;
        cout << "Division: " << student.division << endl;
        cout << "Address: " << student.address << endl;
    }

    inFile.close();
}

int main() {
    int choice;
    do {
        cout << "\nMenu: ";
        cout << "\n1. Create student file";
        cout << "\n2. Display student data";
        cout << "\n3. Exit";
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            createFile();
            break;
        case 2:
            displayFile();
            break;
        case 3:
            cout << "Exiting program!" << endl;
            break;
        default:
            cout << "Invalid choice! Please try again." << endl;
        }
    } while (choice != 3);

    return 0;
}
