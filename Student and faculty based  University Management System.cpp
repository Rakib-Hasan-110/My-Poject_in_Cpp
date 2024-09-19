#include <iostream>
#include <string>
using namespace std;
class Course {
private:
    string name;
    string courseID;
    int credits;
public:
    Course() {}
    void setName(string name) {
        this->name = name;
    }
    void setCourseID(string courseID) {
        this->courseID = courseID;
    }
    void setCredits(int credits) {
        this->credits = credits;
    }
    string getName() {
        return name;
    }
    string getCourseID() {
        return courseID;
    }
    int getCredits() {
        return credits;
    }
};

class Student {
private:
    string name;
    int studentID;
    Course course;
    char grade;
public:
    Student() {}
    void setName(string name) {
        this->name = name;
    }
    void setStudentID(int studentID) {
        this->studentID = studentID;
    }
    void setCourse(Course course) {
        this->course = course;
    }
    void setGrade(char grade) {
        this->grade = grade;
    }
    string getName() {
        return name;
    }
    int getStudentID() {
        return studentID;
    }
    Course getCourse() {
        return course;
    }
    char getGrade() {
        return grade;
    }
};

class Faculty {
private:
    string name;
    int facultyID;
    string department;
public:
    Faculty() {}
    void setName(string name) {
        this->name = name;
    }
    void setFacultyID(int facultyID) {
        this->facultyID = facultyID;
    }
    void setDepartment(string department) {
        this->department = department;
    }
    string getName() {
        return name;
    }
    int getFacultyID() {
        return facultyID;
    }
    string getDepartment() {
        return department;
    }
};

class UniversityManagementSystem {
private:
    Student students[100];
    Faculty faculty[100];
    Course courses[100];
    int studentCount;
    int facultyCount;
    int courseCount;
public:
    UniversityManagementSystem() {
        studentCount = 0;
        facultyCount = 0;
        courseCount = 0;
    }
    void addStudent() {
        string name;
        int studentID;
        cout << "Enter student name: ";
        cin.ignore();
        getline(cin, name);
        cout << "Enter student ID: ";
        cin >> studentID;
        students[studentCount].setName(name);
        students[studentCount].setStudentID(studentID);
        studentCount++;
    }
    void addFaculty() {
        string name;
        int facultyID;
        string department;
        cout << "Enter faculty name: ";
        cin.ignore();
        getline(cin, name);
        cout << "Enter faculty ID: ";
        cin >> facultyID;
        cout << "Enter department: ";
        cin.ignore();
        getline(cin, department);
        faculty[facultyCount].setName(name);
        faculty[facultyCount].setFacultyID(facultyID);
        faculty[facultyCount].setDepartment(department);
        facultyCount++;
    }
    void addCourse() {
        string name;
        string courseID;
        int credits;
        cout << "Enter course name: ";
        cin.ignore();
        getline(cin, name);
        cout << "Enter course ID: ";
        cin >> courseID;
        cout << "Enter credits: ";
        cin >> credits;
        courses[courseCount].setName(name);
        courses[courseCount].setCourseID(courseID);
        courses[courseCount].setCredits(credits);
        courseCount++;
    }
    void enrollStudentInCourse() {
        int studentID;
        string courseID;
        cout << "Enter student ID: ";
        cin >> studentID;
        cout << "Enter course ID: ";
        cin >> courseID;
        for (int i = 0; i < studentCount; i++) {
            if (students[i].getStudentID() == studentID) {
                for (int j = 0; j < courseCount; j++) {
                    if (courses[j].getCourseID() == courseID) {
                        students[i].setCourse(courses[j]);
                        cout << "Student enrolled in course successfully." << endl;
                        return;
                    }
                }
                cout << "Course not found." << endl;
                return;
            }
        }
        cout << "Student not found." << endl;
    }
    void displayStudentInfo() {
        int studentID;
        cout << "Enter student ID: ";
        cin >> studentID;
        for (int i = 0; i < studentCount; i++) {
            if (students[i].getStudentID() == studentID) {
                cout << "Student Name: " << students[i].getName() << endl;
                cout << "Student ID: " << students[i].getStudentID() << endl;
                cout << "Course Name: " << students[i].getCourse().getName() << endl;
                cout << "Course ID: " << students[i].getCourse().getCourseID() << endl;
                return;
            }
        }
        cout << "Student not found." << endl;
    }
    void displayFacultyInfo() {
        int facultyID;
        cout << "Enter faculty ID: ";
        cin >> facultyID;
        for (int i = 0; i < facultyCount; i++) {
            if (faculty[i].getFacultyID() == facultyID) {
                cout << "Faculty Name: " << faculty[i].getName() << endl;
                cout << "Faculty ID: " << faculty[i].getFacultyID() << endl;
                cout << "Department: " << faculty[i].getDepartment() << endl;
                return;
            }
        }
        cout << "Faculty not found." << endl;
    }
    void displayCourseInfo() {
        string courseID;
        cout << "Enter course ID: ";
        cin >> courseID;
        for (int i = 0; i < courseCount; i++) {
            if (courses[i].getCourseID() == courseID) {
                cout << "Course Name: " << courses[i].getName() << endl;
                cout << "Course ID: " << courses[i].getCourseID() << endl;
                cout << "Credits: " << courses[i].getCredits() << endl;
                return;
            }
        }
        cout << "Course not found." << endl;
    }
};
int main() {
    UniversityManagementSystem university;
    while (true) {
        cout << "                           Student and faculty based  University Management System                   " << endl;
        cout << "1. Add Student" << endl;
        cout << "2. Add Faculty" << endl;
        cout << "3. Add Course" << endl;
        cout << "4. Enroll Student in Course" << endl;
        cout << "5. Display Student Info" << endl;
        cout << "6. Display Faculty Info" << endl;
        cout << "7. Display Course Info" << endl;
        cout << "8. Exit" << endl;
        int choice;
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                university.addStudent();
                break;
            case 2:
                university.addFaculty();
                break;
            case 3:
                university.addCourse();
                break;
            case 4:
                university.enrollStudentInCourse();
                break;
            case 5:
                university.displayStudentInfo();
                break;
            case 6:
                university.displayFacultyInfo();
                break;
            case 7:
                university.displayCourseInfo();
                break;
            case 8:
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }
    return 0;
}
