// Implementation file for the ProductionWorker class
#include "ProductionWorker.h"

// Mutators
void ProductionWorker::setShift(int s)
{
	shift = s;
}
void ProductionWorker::setPayRate(double r)
{
	payRate = r;
}

// Accessors
int ProductionWorker::getShiftNumber() const
{
	return shift;
}
string ProductionWorker::getShiftName() const
{
	if (getShiftNumber() == 1)
	{
		return "Day";
	}
	else if (getShiftNumber() == 2)
	{
		return "Night";
	}
	else
	{
		return "Invalid input";
	}
}
double ProductionWorker::getPayRate() const
{
	return payRate;
}

void ProductionWorker::printWorkerData() const
{
	cout << "Name: " << getEmployeeName() << endl;
	cout << "Employee number: " << getEmployeeNumber() << endl;
	cout << "Hire date: " << getHireDate() << endl;
	cout << "Shift: " << getShiftName() << endl;
	cout << "Shift number: " << getShiftNumber() << endl;
	cout << "Pay rate: " << getPayRate() << endl;
}

// Modified createNewProductionWorker code
ProductionWorker* ProductionWorker::createNewProductionWorker()
{
	// Variables
	string aName;
	string aDate;
	int s;
	double r;
	bool keepRunning = true;

	while (keepRunning) // While loop to keep repeating until a new ProductionWorker is created
	{
		// Ask user for information
		cout << "Enter name of new Employee: ";
		getline(cin, aName);
		cout << "Enter hire date of new employee: ";
		getline(cin, aDate);
		cout << "Enter shift for new employee (1=day, 2=night): ";
		cin >> s;
		cout << "Enter hourly pay rate for new employee: ";
		cin >> r;
		cin.ignore();

		try // block that calls function
		{
			// Validate Inputs
			testHireDate(aDate);
			testShift(s);
			testPayRate(r);

			// Call Constructor
			ProductionWorker* newWorker = new ProductionWorker(aName, aDate, s, r);
			keepRunning = false;
			return newWorker;
		}
		// Catch blocks
		catch (InvalidShift& e)
		{
			cout << "Error: Invalid shift number: " << e.getInvalidShift() << endl;
		}
		catch (InvalidPayRate& e)
		{
			cout << "Error: Invalid pay rate: " << e.getInvalidPayRate() << endl;
		}
		catch (InvalidHireDate& e)
		{
			cout << "Error: Invalid hire date [" << e.getInvalidHireDate() << "]: Hire date must be in MM/DD/YYYY format." << endl;
		}
	}

	return nullptr;

}

// Test if shift number is below 1 or above 2
bool testShift(int shift)
{
	if (shift < 1 || shift > 2)
		throw InvalidShift(shift);
	return true;
}

// Test if payRate is negative
bool testPayRate(double rate)
{
	if (rate < 0)
		throw InvalidPayRate(rate);
	return true;
}
