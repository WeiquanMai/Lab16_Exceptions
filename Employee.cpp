// Implementation file for the Employee class
// Modified code obtained from Professor Morgan

#include "Employee.h"
#include <string>
#include <cctype>
using namespace std;

int Employee::lastEmployeeNumberIssued = 0;   // Sequential employee number

// Default constructor
Employee::Employee()
{
	lastEmployeeNumberIssued++;
	employeeNumber = lastEmployeeNumberIssued;
	employeeName = "";
	hireDate = "";
}


// Constructor
Employee::Employee(string aName, string aDate)
{
	lastEmployeeNumberIssued++;
	employeeNumber = lastEmployeeNumberIssued;
	employeeName = aName;
	hireDate = aDate;
}

// Mutators
void Employee::setEmployeeName(string n)
{
	employeeName = n;
}


void Employee::setHireDate(string date)
{
	hireDate = date;
}

// Accessors
string Employee::getEmployeeName() const
{
	return employeeName;
}

int Employee::getEmployeeNumber() const
{
	return employeeNumber;
}

string Employee::getHireDate() const
{
	return hireDate;
}

int Employee::getLastEmployeeNumberIssued()
{
	return lastEmployeeNumberIssued;
}
// Test if hireDate is in correct format
bool testHireDate(string hireDate)
{
	if (hireDate.length() != 10)
		throw InvalidHireDate(hireDate);
	else if (hireDate[2] != '/' || hireDate[5] != '/')
		throw InvalidHireDate(hireDate);
	else if (!isdigit(hireDate[0]) || !isdigit(hireDate[1]) || !isdigit(hireDate[3]) || !isdigit(hireDate[4]) || !isdigit(hireDate[6])
		|| !isdigit(hireDate[7]) || !isdigit(hireDate[8]) || !isdigit(hireDate[9]))
		throw InvalidHireDate(hireDate);
	return true;
}
