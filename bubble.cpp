#include <iostream>
#include <string>
using namespace std;

struct Student {
    int rollNo;
    string name;
    float sgpa;
};

void swap(Student &a, Student &b) {
    Student temp = a;
    a = b;
    b = temp;
}

void bubbleSort(Student students[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (students[j].rollNo > students[j + 1].rollNo) {
                swap(students[j], students[j + 1]);
            }
        }
    }
}

void displayStudents(Student students[], int n) {
    cout << "\nRoll Call List (Sorted by Roll Number):\n";
    cout << "---------------------------------------\n";
    cout << "Roll No\tName\tSGPA\n";
    cout << "---------------------------------------\n";
    for (int i = 0; i < n; i++) {
        cout << students[i].rollNo << "\t" << students[i].name << "\t" << students[i].sgpa << endl;
    }
    cout << "---------------------------------------\n";
}

int main() {
    int numStudents;

    cout << "Enter the number of students: ";
    cin >> numStudents;

    if (numStudents < 1) {
        cout << "Number of students must be at least 1.\n";
        return 0;
    }

    Student students[numStudents];
    cout << "\nEnter student details (Roll No, Name, SGPA):\n";
    for (int i = 0; i < numStudents; i++) {
        cout << "Student " << i + 1 << ":\n";
        cout << "  Roll Number: ";
        cin >> students[i].rollNo;
        cout << "  Name (single word): ";
        cin >> students[i].name;
        cout << "  SGPA: ";
        cin >> students[i].sgpa;
    }
    bubbleSort(students, numStudents);
    displayStudents(students, numStudents);

    return 0;
}
