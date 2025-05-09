/*
CSC237- C++
Project Name: Inheritance
Student: Weiquan Mai
Date: April 3, 2025
Description: Lab16a builds on Lab15a with exceptions handling.
The following exceptions are added to the program:
InvalidShift - shift value must be either 1 or 2
InvalidPayRate - payRate must be above 0
InvalidHireDate- hire date must be in MM/DD/YYYY format

*/

#include <iostream>
#include <string>
#include "ProductionWorker.h"
#include "Employee.h"
using namespace std;

// Function Prototypes
void outputHelpText();

int main()
{
	// Variables
	string command;
	bool keepRunning = true;
	ProductionWorker* worker = nullptr;

	while (keepRunning == true)
	{
		// Prompt user for command input. Use command input to control function of the program
		cout << "Enter command (or 'h' for help): ";
		getline(cin, command);

		// Ignore empty commands
		if (command == " ") {
			cin.ignore();
		}
		else if (command == "c" || command == "C")
		{

			worker = ProductionWorker::createNewProductionWorker();

		}
		else if (command == "h" || command == "H")
		{
			outputHelpText();
		}
		else if (command == "p" || command == "P")
		{
			if (worker != nullptr)
			{
				worker->printWorkerData();
			}
			else
			{
				cout << "No ProductionWorker has been created yet." << endl;
			}
		}
		else if (command == "q" || command == "Q")
		{
			keepRunning = false;
		}
		else
		{
			cout << "Invalid command: " << command << endl;
		}
	} // End of while loop

	delete worker;
	cout << "Exiting the program.";
	return 0;
}

void outputHelpText()
{
	// Output list of supported commands
	cout << "Supported commands: " << endl;
	cout << "         c        create a new ProductionWorker object." << endl;
	cout << "         h        print help text." << endl;
	cout << "         p        proint ProductionWorker information." << endl;
	cout << "         q        quit (end the program.)" << endl;
}
