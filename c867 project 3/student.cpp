#include <iostream>
#include <string>
#include "student.h"
using namespace std;

/*Constructor*/
Student::Student()
{
    this->studentID = "";
    this->firstName = "";
    this->lastName = "";
    this->email = "";
    this->age = 0;
    for (int i = 0; i < daysInCourseArraySize; i++) this->daysInCourse[i] = 0;
    this -> degreeProgram = SECURITY;
}
Student::Student(string studentID, string firstName, string lastName, string email, int age, int daysInCourse[],DegreeProgram degreeProgram)
{
    this->studentID = studentID;
    this->firstName = firstName;
    this->lastName = lastName;
    this->email = email;
    this->age = age;
    for (int i = 0; i < daysInCourseArraySize; i++) this->daysInCourse[i] = daysInCourse[i];
    this->degreeProgram = degreeProgram;
}
//Destructor
Student::~Student() {}

//Getters
string Student::getstudentID() { return this->studentID; }
string Student::getfirstName() { return this->firstName; }
string Student::getlastName() { return this->lastName; }
string Student::getemail() { return this-> email; }
int Student::getage() { return this->age; }
int* Student::getdaysInCourse() {return this->daysInCourse; }
DegreeProgram Student::getdegreeProgram() {return this -> degreeProgram; }

//Setters
void Student::setstudentID(string studentID) { this->studentID = studentID; }
void Student::setfirstName(string firstName) { this->firstName = firstName; }
void Student::setlastName(string lastName) { this->lastName = lastName; }
void Student::setemail(string email) { this->email = email; }
void Student::setage(int age) { this->age = age; }
void Student::setdaysInCourse(int daysInCourse[]) { for (int i = 0; i < daysInCourseArraySize; i++) this->daysInCourse[i] = daysInCourse[i]; }
void Student::setDegreeProgram(DegreeProgram degreeProgram) { this->degreeProgram  = degreeProgram; }
void Student::printHeader()
{
    cout << "output format: ID | First | Last | Age | Days | Degree\n";
}
void Student::print()
{
    cout << this->getstudentID() << '\t';
    cout << this->getfirstName() << '\t';
    cout << this->getlastName() << '\t';
    cout << this->getage() << '\t';
    cout << this->getdaysInCourse()[0] << ',';
    cout << this->getdaysInCourse()[1] << ',';
    cout << this->getdaysInCourse()[2] << 't';
    cout << degreeProgramStrings[this->getdegreeProgram()] << '\n';

}
