#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Student {
private:
    int id;
    string name;
    int age;
    string grade;

public:
    // Constructor to initialize student details
    Student(int id, const string& name, int age, const string& grade)
        : id(id), name(name), age(age), grade(grade) {}

    // Setters
    void setId(int id) { this->id = id; }
    void setName(const string& name) { this->name = name; }
    void setAge(int age) { this->age = age; }
    void setGrade(const string& grade) { this->grade = grade; }

    // Getters
    int getId() const { return id; }
    string getName() const { return name; }
    int getAge() const { return age; }
    string getGrade() const { return grade; }

    // Display student details
    void display() const {
        cout << "ID: " << id << ", Name: " << name << ", Age: " << age << ", Grade: " << grade << endl;
    }
};

class StudentDatabase {
private:
    vector<Student> students;

public:
    // Add a new student to the database
    void addStudent(const Student& student) {
        students.push_back(student);
    }

    // Delete a student from the database by ID
    void deleteStudent(int id) {
        for (auto it = students.begin(); it != students.end(); ++it) {
            if (it->getId() == id) {
                students.erase(it);
                cout << "Student with ID " << id << " deleted." << endl;
                return;
            }
        }
        cout << "Student with ID " << id << " not found." << endl;
    }

    // Display all students in the database
    void displayAllStudents() const {
        for (const auto& student : students) {
            student.display();
        }
    }

    // Find and display a student by ID
    void findStudentById(int id) const {
        for (const auto& student : students) {
            if (student.getId() == id) {
                student.display();
                return;
            }
        }
        cout << "Student with ID " << id << " not found." << endl;
    }
};

int main() {
    StudentDatabase db;

    // Add some students
    db.addStudent(Student(1, "ABC", 20, "A"));
    db.addStudent(Student(2, "BCA", 21, "B"));
    db.addStudent(Student(3, "XYZ", 19, "A"));

    // Display all students
    cout << "All Students:" << endl;
    db.displayAllStudents();

    // Find a student by ID
    cout << "\nFind Student with ID 2:" << endl;
    db.findStudentById(2);

    // Delete a student by ID
    cout << "\nDelete Student with ID 2:" << endl;
    db.deleteStudent(2);

    // Display all students again to confirm deletion
    cout << "\nAll Students after deletion:" << endl;
    db.displayAllStudents();

    return 0;
}
