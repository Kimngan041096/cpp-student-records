#include <iostream>
#include <string>
#include <iomanip>
#include <algorithm>
#include <vector>

using namespace std;

namespace StudentUtils {

    // Enumeration for grade levels
    enum GradeLevel { FRESHMAN = 1, SOPHOMORE, JUNIOR, SENIOR };

    // Using alias for better readability
    using GPA = float;

    struct Student {
        string name;
        GradeLevel grade;
        GPA gpa;
    };

    // Convert string to uppercase
    void formatName(string &name) {
        transform(name.begin(), name.end(), name.begin(), ::toupper);
    }

    // Convert enum to string for display
    string gradeLevelToString(GradeLevel grade) {
        switch (grade) {
            case FRESHMAN: return "Freshman";
            case SOPHOMORE: return "Sophomore";
            case JUNIOR: return "Junior";
            case SENIOR: return "Senior";
            default: return "Unknown";
        }
    }

    // Display student info
    void displayStudentInfo(const Student &student) {
        cout << "Name: " << student.name << endl;
        cout << "Grade Level: " << gradeLevelToString(student.grade) << endl;
        cout << "GPA: " << fixed << setprecision(2) << student.gpa << endl;
        cout << "----------------------" << endl;
    }

    // Sort students alphabetically by name
    void sortStudentsByName(vector<Student> &students) {
        sort(students.begin(), students.end(), [](const Student &a, const Student &b) {
            return a.name < b.name;
        });
    }
}

int main() {
    using namespace StudentUtils;

    vector<Student> students;
    char choice;

    do {
        string name;
        int gradeInput;
        GPA gpa;

        cin.ignore();  // flush newline
        cout << "Enter student name: ";
        getline(cin, name);

        cout << "Enter grade level (1=Freshman, 2=Sophomore, 3=Junior, 4=Senior): ";
        cin >> gradeInput;

        if (gradeInput < 1 || gradeInput > 4) {
            cout << "Invalid grade level. Please enter a value between 1 and 4." << endl;
            continue;
        }

        cout << "Enter GPA: ";
        cin >> gpa;

        if (gpa < 0.0 || gpa > 4.0) {
            cout << "Invalid GPA. Must be between 0.00 and 4.00." << endl;
            continue;
        }

        formatName(name);

        Student s = {name, static_cast<GradeLevel>(gradeInput), gpa};
        students.push_back(s);

        cout << "Add another student? (y/n): ";
        cin >> choice;

    } while (tolower(choice) == 'y');

    if (students.empty()) {
        cout << "\nNo student records to display." << endl;
        return 0;
    }

    // Sort and display
    sortStudentsByName(students);

    cout << "\n🎓 Sorted Student Records:\n----------------------" << endl;
    for (const auto &student : students) {
        displayStudentInfo(student);
    }

    return 0;
}
