#include "roster.h"
#include <iostream>
#include <string>
using namespace std;

int main()
{
    cout << "Scripting and Programming: Applications\n";
    cout << "Language C++\n";
    cout << "WGU ID: 010045967\n";
    cout << "Name: Precious Naff\n" << "\n";
    
    const string studentData[] = {
                "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
                "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
                "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
                "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
                "A5,Precious,Naff,pnaff@wgu.edu,21,36,31,15,SOFTWARE"
            };
    
    const int numStudents = 5;
    Roster roster;
    
    for (int i = 0; i < numStudents; i++) roster.parse(studentData[i]);
    cout << "Displaying all students: " << std::endl;
    roster.printAll();
    cout << std::endl;
    
    cout << "Displaying invalid emails" << std::endl;
    roster.printInvalidEmails();
    cout << std::endl;
        
    for (int i = 0; i < 1; i++){
        cout << "Displaying average days to complete courses: " << std::endl;
            roster.printAverageDays(roster.classRosterArray[i]->getstudentID());
    }
    for (int i = 0; i < 3; i++)
    {
        cout << "Displaying by Degree Program: " << degreeProgramStrings[i] << std::endl;
            roster.printByDegreeProgram((DegreeProgram)i);
        }
        
        
        cout << "Removing student with ID A3" << std::endl;
        roster.removeStudentByID("A3");
        cout << std::endl;
        
        cout << "Removing student with ID A3" << std::endl;
        roster.removeStudentByID("A3");
        cout << std::endl;
        
      
        return 0;
};
