#include <iostream>
#include <vector>
using namespace std;

class Student {
private:
    string name;
    int rollNo;
    int marks[3];
    char grade;

    float calculateAverage() const;
    char calculateGrade(float avg) const;

public:
    void input();
    void display() const;
    int getRollNo() const;
    float getAverage() const;
};


float Student::calculateAverage() const {
    float sum = 0;
    for (int i = 0; i < 3; i++) {
        sum += marks[i];
    }
    return sum / 3;
}

char Student::calculateGrade(float avg) const {
    if (avg >= 90) return 'A';
    if (avg >= 80) return 'B';
    if (avg >= 70) return 'C';
    if (avg >= 60) return 'D';
    return 'F';
}

void Student::input() {
    cout << "Enter name: ";
    cin.ignore();
    getline(cin, name);

    cout << "Enter roll number: ";
    cin >> rollNo;

    cout << "Enter marks:\n";
    for (int i = 0; i < 3; i++) {
        cout << "Subject " << i + 1 << ": ";
        cin >> marks[i];
    }

    float avg = calculateAverage();
    grade = calculateGrade(avg);
}

void Student::display() const {
    cout << "Name: " << name << endl;
    cout << "Roll No: " << rollNo << endl;

    cout << "Marks: ";
    for (int i = 0; i < 3; i++) {
        cout << marks[i] << " ";
    }
    cout << endl;

    cout << "Average: " << calculateAverage() << endl;
    cout << "Grade: " << grade << endl;
}

int Student::getRollNo() const {
    return rollNo;
}

float Student::getAverage() const {
    return calculateAverage();
}


class StudentManagementSystem {
private:
    vector<Student> students;

    int findStudentIndex(int rollNo);

public:
    void addStudent();
    void displayStudents();
    void searchStudent();
    void deleteStudent();
    void showClassAverage();
};


int StudentManagementSystem::findStudentIndex(int rollNo) {
    for (int i = 0; i < students.size(); i++) {
        if (students[i].getRollNo() == rollNo)
            return i;
    }
    return -1;
}

void StudentManagementSystem::addStudent() {
    Student s;
    s.input();

    if (findStudentIndex(s.getRollNo()) != -1) {
        cout << "Roll number already exists.\n";
        return;
    }

    students.push_back(s);
    cout << "Student added successfully.\n";
}

void StudentManagementSystem::displayStudents() {
    if (students.empty()) {
        cout << "No records found.\n";
        return;
    }

    for (int i = 0; i < students.size(); i++) {
        cout << "\nStudent " << i + 1 << endl;
        students[i].display();
    }
}

void StudentManagementSystem::searchStudent() {
    int rollNo;
    cout << "Enter roll number: ";
    cin >> rollNo;

    int idx = findStudentIndex(rollNo);

    if (idx == -1) {
        cout << "Student not found.\n";
        return;
    }

    cout << "\nStudent found:\n";
    students[idx].display();
}

void StudentManagementSystem::deleteStudent() {
    int rollNo;
    cout << "Enter roll number to delete: ";
    cin >> rollNo;

    int idx = findStudentIndex(rollNo);

    if (idx == -1) {
        cout << "Student not found.\n";
        return;
    }

    students.erase(students.begin() + idx);
    cout << "Student deleted.\n";
}

void StudentManagementSystem::showClassAverage() {
    if (students.empty()) {
        cout << "No records.\n";
        return;
    }

    float sum = 0;
    for (int i = 0; i < students.size(); i++) {
        sum += students[i].getAverage();
    }

    cout << "Class Average: " << sum / students.size() << endl;
}

int main() {
    StudentManagementSystem sms;
    int choice;

    while (true) {
        cout << "\n===== MENU =====\n";
        cout << "1. Add Student\n";
        cout << "2. Display\n";
        cout << "3. Search\n";
        cout << "4. Delete\n";
        cout << "5. Class Average\n";
        cout << "0. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1: sms.addStudent(); break;
            case 2: sms.displayStudents(); break;
            case 3: sms.searchStudent(); break;
            case 4: sms.deleteStudent(); break;
            case 5: sms.showClassAverage(); break;
            case 0:
                cout << "Exiting...\n";
                return 0;
            default:
                cout << "Invalid choice.\n";
        }
    }
}