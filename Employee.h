// Specification file for the Employee class
// Modified code obtained from Professor Morgan

#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include <string>
using namespace std;

class Employee
{
private:
	static int lastEmployeeNumberIssued;   // Sequential employee number
	int employeeNumber;                    // Employee number for current employee
	string employeeName;		           // Employee name
	string hireDate;	                   // Hire date

public:
	// Constructors
	Employee();
	Employee(string aName, string aDate);

	// Mutators
	void setEmployeeName(string n);
	void setHireDate(string date);

	// Accessors
	string getEmployeeName() const;
	int getEmployeeNumber() const;
	string getHireDate() const;
	static int getLastEmployeeNumberIssued();
};


// InvalidHireDate exception class
class InvalidHireDate {
private:
	string hireDate;
public:
	InvalidHireDate(string input)
	{
		hireDate = input;
	}
	string getInvalidHireDate() const
	{
		return hireDate;
	}
};
bool testHireDate(string hireDate);

#endif
