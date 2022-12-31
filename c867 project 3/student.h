#pragma once
#include <iostream>
#include <iomanip>
#include "degree.h"

using std::cout;
using std::string;

class Student {
public:
    const static int daysInCourseArraySize = 3;
    
private:
    string studentID;
    string firstName;
    string lastName;
    string email;
    
    int age;
    int daysInCourse[daysInCourseArraySize];
    DegreeProgram degreeProgram;
    
public:
    //Constructors
    Student ();
    Student (string studentID, string firstName, string lastName, string email, int age, int daysInCourse[], DegreeProgram degreeProgram);
    
    //Destructor
    ~Student ();
    
    //Getters
    string getstudentID ();
    string getfirstName ();
    string getlastName ();
    string getemail ();
    int getage ();
    int* getdaysInCourse ();
    DegreeProgram getdegreeProgram ();
    
    //Setters
    void setstudentID (string studentID);
    void setfirstName (string firstName);
    void setlastName (string lastName);
    void setemail (string email);
    void setage (int age);
    void setdaysInCourse (int daysInCourse[]);
    void setDegreeProgram (DegreeProgram degreeProgram);
    
    static void printHeader();
    
    void print();
};

