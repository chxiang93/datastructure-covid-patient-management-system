/*
Group Member
1. Sue Chen Xiang - B032010034
2. Poh Soon Heng - B032010010
3. Nor Aily Binti Rozali - B032010475
4. Beh Kar Soon - B032010466
*/
#include <iostream>
#include <cctype>
#include <cstdlib>
#include <limits>
#include <fstream>
#include "PatientList.h"
#include "Queue.h"
using namespace std;

int main()
{
	PatientList pl;		//instantiation of object pl
	Queue <int> wait;	//instantiation of object wait
	int choice;
	char ch;

	ifstream inFile("save.dat", ios::binary);	//read in the data of patient served previously
	inFile.read((char*)&pl, sizeof(pl));
	
	cout << "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n";
	cout << "@@ _______________________________________________________________________________________ @@\n";
	cout << "@@|                                                                                       |@@\n";
	cout << "@@|                                                                                       |@@\n";
	cout << "@@|                                                                                       |@@\n";
	cout << "@@|                                                                                       |@@\n";
	cout << "@@|                                                                                       |@@\n";
	cout << "@@|                                           		                                  |@@\n";
	cout << "@@|                                   WELCOME TO                                          |@@\n";
	cout << "@@|                                                                                       |@@\n";
	cout << "@@|                           COVID PATIENT MANAGEMENT SYSTEM                             |@@\n";
	cout << "@@|                                                                                       |@@\n";
	cout << "@@|                                                                                       |@@\n";
	cout << "@@|                                                                                       |@@\n";
	cout << "@@|                                                                                       |@@\n";
	cout << "@@|                                                                                       |@@\n";
	cout << "@@|                                                                                       |@@\n";
	cout << "@@|_______________________________________________________________________________________|@@\n";
	cout << "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n\n";
	
	system("pause");

	do
	{
		system("cls");
		cout << "************************************************************************" << endl;
		cout << "                  COVID PATIENT MANAGEMENT SYSTEM" << endl;
		cout << "************************************************************************" << endl;
		cout << "No. of patient waiting: " << wait.numOfPatient() << "   Current number: ";
		cout << wait.firstPatient() << "   Next number: " << wait.nextPatient() << endl;
		cout << "************************************************************************" << endl;
		cout << "Welcome to the covid patient management system" << endl;
		cout << "What do you want to do with this system?" << endl;
		cout << "1. Get new waiting number" << endl;
		cout << "2. Add a new patient record" << endl;
		cout << "3. Search for tha data of a patient" << endl;
		cout << "4. Delete a patient data" << endl;
		cout << "5. Edit/update a patient data" << endl;
		cout << "6. Sort patient data ascending" << endl;
		cout << "7. Sort patient data descending" << endl;
		cout << "8. Display all patient" << endl;
		cout << "9. Exit the program" << endl;
		cout << "************************************************************************" << endl;
		cout << "Please enter number 1 to 9 to proceed: ";
		cin >> choice;

		while (choice <= 0 || choice >= 10 || cin.fail())	//input validation
		{
			cin.clear();
			cin.ignore(numeric_limits <streamsize>::max(), '\n');
			cout << "\nI'm sorry but the valid choice is only range from 1 to 9. Please try again" << endl;
			cout << "Please enter number 1 to 9 to proceed: ";
			cin >> choice;
		}

		switch (choice)
		{
		case 1:
		{
			wait.enqueue();
			break;
		}
		case 2:
			if (wait.empty())
			{
				cout << "\nThere is currently no patient waiting" << endl;
				break;
			}
			pl.addPatient();

			wait.dequeue();
			break;

		case 3:
		{
			int id;
			cout << "\nPlease enter the id of the patient you want to search\n";
			cout << "ID: ";
			cin >> id;
			
			if (pl.searchPatient(id))
				pl.displaySearchPatient();
			else
				cout << "\nThe record of the patient is not found\n";
			break;
		}
		case 4:
				pl.deletePatient();
			break;
		
		case 5:
		{
			cout << "\nPlease enter the id of the patient you want to edit/update\n";
			cout << "ID: ";
			int id;
			cin >> id;

			if (pl.searchPatient(id))
				pl.updatePatient();
			else
				cout << "\nNo record found\n";
			break;
		}
		case 6:
			pl.sortAsc();
			break;

		case 7:
			pl.sortDesc();
			break;

		case 8:
			cout << endl;
			pl.displayPatient();
			break;

		case 9:
			exit(EXIT_SUCCESS);		//exit the program
			break;
		}

		do
		{
			cout << "\n***Please enter Y to return to main menu, enter N to exit the program: ";
			cin >> ch;
		} while (tolower(ch) != 'y' && tolower(ch) != 'n');

		ofstream outFile;
		outFile.open("save.dat", ios::binary);	//write new data of patient to the file
		outFile.write((char*)&pl, sizeof(pl));

	} while (tolower(ch) == 'y');

	return 0;
}