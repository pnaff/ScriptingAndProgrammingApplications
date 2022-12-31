#include "student.h"

class Roster
{
private:
    int lastIndex = -1;
    const static int numStudents = 5;

public:
    Student* classRosterArray[numStudents];
    void parse(string row);
    void add(string studentID,
             string firstName,
             string lastName,
             string email,
             int age,
             int daysInCourse1,
             int daysInCourse2,
             int daysInCourse3,
             DegreeProgram degreeProgram);

        void printAll();
        void printAverageDays(string studentID);
        void printInvalidEmails();/*emails must have a ".", an "@" and no " "*/
        void printByDegreeProgram(DegreeProgram degreeProgram);
        void removeStudentByID (string studentID);

        Student* getStudentAt(int index);
    ~Roster();
    
};
