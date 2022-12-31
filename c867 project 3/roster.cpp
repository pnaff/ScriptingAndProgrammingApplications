#include "roster.h"
#include <iostream>
#include <string>
using namespace std;

void Roster::parse(string studentdata)
{
    
            
    int rhs = studentdata.find(",");
    string studentID = studentdata.substr(0, rhs);
        
    int lhs = rhs + 1;
    rhs = studentdata.find(",", lhs);
    string firstName = studentdata.substr(lhs, rhs - lhs);
    
    lhs = rhs + 1;
    rhs = studentdata.find(",", lhs);
    string lastName = studentdata.substr(lhs, rhs - lhs);
    
    lhs = rhs + 1;
    rhs = studentdata.find(",", lhs);
    string email = studentdata.substr(lhs, rhs - lhs);
    
    lhs = rhs + 1;
    rhs = studentdata.find(",", lhs);
    int age = stoi(studentdata.substr(lhs, rhs - lhs));
    
    lhs = rhs + 1;
    rhs = studentdata.find(",", lhs);
    int daysInCourse1 = stoi(studentdata.substr(lhs, rhs - lhs));
    
    lhs = rhs + 1;
    rhs = studentdata.find(",", lhs);
    int daysInCourse2 = stoi(studentdata.substr(lhs, rhs - lhs));
    
    lhs = rhs + 1;
    rhs = studentdata.find(",", lhs);
    int daysInCourse3 = stoi(studentdata.substr(lhs, rhs - lhs));
    
    lhs = rhs + 1;
    rhs = studentdata.find(",", lhs);
    string degree = studentdata.substr(lhs, rhs - lhs);
    
    DegreeProgram deg = SECURITY;
        
        if (degree == "NETWORK") {
            deg = NETWORK;
        }
        if (degree == "SOFTWARE") {
            deg = SOFTWARE;
        }
    add(studentID, firstName, lastName, email, age, daysInCourse1, daysInCourse2, daysInCourse3, deg);
}
void Roster::add(string studentID, string firstName, string lastName, string email, int  age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram)
{
    int parr[3] = { daysInCourse1, daysInCourse2, daysInCourse3 };
    classRosterArray[++lastIndex] = new Student(studentID, firstName, lastName, email, age, parr, degreeProgram);
    
}
void Roster::printAll()
{
    Student::printHeader();
    for (int i = 0; i <= Roster::lastIndex; i++)
    {
        cout << classRosterArray[i] ->getstudentID(); cout << '\t';
        cout << "First Name: " << classRosterArray[i] ->getfirstName(); cout << '\t';
        cout << "Last Name: " << classRosterArray[i] ->getlastName(); cout << '\t';
        cout << "Age: " << classRosterArray[i] ->getage(); cout << '\t';
        cout << "daysInCourse: {" << classRosterArray[i]->getdaysInCourse()[0] << ", " << classRosterArray[i]->getdaysInCourse()[1] << ", " << classRosterArray[i]->getdaysInCourse()[2] << "} ";
        cout << "Degree Program: " <<degreeProgramStrings[classRosterArray[i] ->getdegreeProgram()]; cout << std::endl;
        
    }
}
void Roster::printAverageDays(string studentID){
        for (int i = 0; i <= Roster::lastIndex; i++){
        
        cout << "Student ID: " << classRosterArray[i]->getstudentID() << ",";
        cout << " average days in course: " << (classRosterArray[i]->getdaysInCourse()[0] + classRosterArray[i]->getdaysInCourse()[1] + classRosterArray[i]->getdaysInCourse()[2]) /3 << std::endl;
        }
    cout << std::endl;
}

void Roster::printInvalidEmails()
{
    bool any = false;
    for (int i = 0; i <= Roster::lastIndex; i++){
        string email = (classRosterArray[i]->getemail());
        if (email.find('@') == string::npos ||
            email.find('.') == string::npos ||
            email.find(' ') != string::npos)
        {
            any = true;
            cout << classRosterArray[i]->getstudentID() << ": " << classRosterArray[i]->getemail() << std::endl;
        }
    }
    if (!any) cout << "NONE" << std::endl;
}

void Roster::printByDegreeProgram(DegreeProgram degreeProgram)
{
    Student::printHeader();
    for (int i = 0; i <= Roster::lastIndex; i++){
        if (Roster::classRosterArray[i]->getdegreeProgram() == degreeProgram) classRosterArray[i]->print();
    }
    cout << std::endl;
}


void Roster::removeStudentByID(string studentID)
{
    bool success = false;
    for (int i = 0; i <= Roster::lastIndex; i++){
        if (classRosterArray[i]->getstudentID() == studentID){
            success = true;
            if (i < numStudents - 1){
                Student* temp = classRosterArray[i] = classRosterArray[numStudents - 1];
                classRosterArray[numStudents - 1] = temp;
            }
            Roster::lastIndex--;
        }
    }
    if (success)
    {
        cout << "Student " << studentID << " removed from table." << std::endl << std::endl;
        this->printAll();
    }
    else cout << "The student with ID: " << studentID << " was not found." << std::endl << std::endl;
}

Roster::~Roster() //Destructor
{
    cout << "Destructor called!" << std::endl << std::endl;
    for (int i = 0; i < numStudents; i++)
    {
        cout << "Destroying student #" << i + 1 << std::endl << std::endl;
        classRosterArray[i] = nullptr;
        //delete classRosterArray
        
        
    }
}
