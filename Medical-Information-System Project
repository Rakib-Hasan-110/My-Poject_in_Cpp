#include <iostream>
#include <vector>
#include <string>
using namespace std;

class StudentMedicalInfo {
private:
    int id;
    string name;
    int age;
    string medicalCondition;
    string prescribedMedication;

public:
    // Constructor to initialize student medical details
    StudentMedicalInfo(int id, const string& name, int age, const string& medicalCondition, const string& prescribedMedication)
        : id(id), name(name), age(age), medicalCondition(medicalCondition), prescribedMedication(prescribedMedication) {}

    // Setters
    void setId(int id) { this->id = id; }
    void setName(const string& name) { this->name = name; }
    void setAge(int age) { this->age = age; }
    void setMedicalCondition(const string& medicalCondition) { this->medicalCondition = medicalCondition; }
    void setPrescribedMedication(const string& prescribedMedication) { this->prescribedMedication = prescribedMedication; }

    // Getters
    int getId() const { return id; }
    string getName() const { return name; }
    int getAge() const { return age; }
    string getMedicalCondition() const { return medicalCondition; }
    string getPrescribedMedication() const { return prescribedMedication; }

    // Display student medical details
    void display() const {
        cout << "ID: " << id << ", Name: " << name << ", Age: " << age << ", Medical Condition: " << medicalCondition << ", Prescribed Medication: " << prescribedMedication << endl;
    }
};

class StudentMedicalDatabase {
private:
    vector<StudentMedicalInfo> students;

public:
    // Add a new student to the database
    void addStudent(const StudentMedicalInfo& student) {
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
    StudentMedicalDatabase db;

    // Add some students
    db.addStudent(StudentMedicalInfo(1, "John Doe", 20, "Asthma", "Inhaler"));
    db.addStudent(StudentMedicalInfo(2, "Jane Smith", 21, "Diabetes", "Insulin"));
    db.addStudent(StudentMedicalInfo(3, "Emily Davis", 19, "Allergy", "Antihistamine"));

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
