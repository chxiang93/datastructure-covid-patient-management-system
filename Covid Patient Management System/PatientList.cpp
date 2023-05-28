//PatientList.cpp
#include "PatientList.h"

PatientList::PatientList()
{
	size = 0;
}

int PatientList::numberOfPatient()
{
	return size;
}

void PatientList::addPatient()
{
	if (size == MAXSIZE)
	{
		cout << "\n***There is no more place left***\n";
		return;
	}

	cout << "\nPlease enter the information of the new patient\n\n";
	

	cout << "Name\t\t\t\t\t: ";
	cin.ignore();
	getline(cin, p[size].patient_name);

	cout << "ID number (eg: 223)\t\t\t: ";
	cin >> p[size].patient_ID;

	cout << "Address\t\t\t\t\t: ";
	cin.ignore();
	getline(cin, p[size].patient_address);

	cout << "Gender (Male or Female)\t\t\t: ";
	getline(cin, p[size].patient_gender);

	cout << "Age\t\t\t\t\t: ";
	cin >> p[size].patient_age;

	cout << "Confirmed positive date (dd/mm/yyyy)\t: ";
	cin.ignore();
	getline(cin, p[size].patient_confirmed_positive_date);

	size++;
}

void PatientList::deletePatient()
{
	if (size == 0)
	{
		cout << "***No more item to be deleted*****";
		return;
	}

	int patient_ID;
	cout << "\nEnter patient id that you want to delete: ";
	cin >> patient_ID;

	cout << "\nDeleting...";

	if (searchPatient(patient_ID))
	{
		for (int index = locWanted; index < size - 1; index++)
		{
			p[index] = p[index + 1];
		}

		cout << "\nThe data is deleted successfully\n";
		size--;
	}
	else
		cout << "\nThe record of the patient is not found\n";

}

void PatientList::displayPatient()
{
	cout << left << "        " << setw(25) << "Name" << "ID" << "          " << setw(30) << "Address";
	cout << setw(10) << "Gender" << setw(5) << "Age" << setw(20) << "ConfirmedPositiveDate";
	cout << "     " << endl;
	for (int i = 0; i < size; i++)
	{
		cout << i + 1 << ") " << setw(30) << p[i].patient_name;
		cout << p[i].patient_ID << "     ";
		cout << setw(35) << p[i].patient_address;
		cout << setw(10) << p[i].patient_gender;
		cout << p[i].patient_age << "        ";
		cout << setw(20) << p[i].patient_confirmed_positive_date;
		cout << endl;
	}

}

void PatientList::displaySearchPatient()
{
	cout << "\n\nName\t\t\t\t\t: " << p[locWanted].patient_name << endl;

	cout << "ID number (eg: 223)\t\t\t: " << p[locWanted].patient_ID << endl;

	cout << "Address\t\t\t\t\t: " << p[locWanted].patient_address << endl;

	cout << "Gender (Male or Female)\t\t\t: " << p[locWanted].patient_gender << endl;

	cout << "Age\t\t\t\t\t: " << p[locWanted].patient_age << endl;

	cout << "Confirmed positive date (dd/mm/yyyy)\t: " << p[locWanted].patient_confirmed_positive_date << endl;
}

void PatientList::updatePatient()
{
	if (size == 0)
	{
		cout << "***There is no data that can be updated*****";
		return;
	}

	cout << "\nPlease enter new information for patient:";
	cout << "\nName\t\t\t\t\t: ";
	cin.ignore();
	getline(cin, p[locWanted].patient_name);

	cout << "ID number (eg: 223)\t\t\t: ";
	cin >> p[locWanted].patient_age;

	cout << "Address\t\t\t\t\t: ";
	cin.ignore();
	getline(cin, p[locWanted].patient_address);

	cout << "Gender (Male or Female)\t\t\t: ";
	getline(cin, p[locWanted].patient_gender);

	cout << "Age\t\t\t\t\t: ";
	cin >> p[locWanted].patient_age;

	cout << "Confirmed positive date (dd/mm/yyyy)\t: ";
	cin.ignore();
	getline(cin, p[locWanted].patient_confirmed_positive_date);

	cout << "\nUpdate Successfully\n" << endl;
}

void PatientList::sortAsc()
{
	int current, walker;
	bool sorted;

	for (current = 0, sorted = false; current < size && !sorted; current++)
	{
		for (walker = size - 1, sorted = true; walker > current; walker--)
		{
			if (tolower(p[walker].patient_name[0]) < tolower(p[walker - 1].patient_name[0]))
			{
				sorted = false;
				PatientData temp;
				temp = p[walker];
				p[walker] = p[walker - 1];
				p[walker - 1] = temp;
			}
		}
	}

	cout << "\nThe data is sorted ascending\n";
}

void PatientList::sortDesc()
{
	int current, walker;
	bool sorted;

	for (current = 0, sorted = false; current < size && !sorted; current++)
	{
		for (walker = size - 1, sorted = true; walker > current; walker--)
		{
			if (tolower(p[walker].patient_name[0]) > tolower(p[walker - 1].patient_name[0]))
			{
				sorted = false;
				PatientData temp;
				temp = p[walker];
				p[walker] = p[walker - 1];
				p[walker - 1] = temp;
			}
		}
	}
	cout << "\nThe data is sorted descending\n";
}

bool PatientList::searchPatient(int id)
{
	int index = 0;
	bool found = false;

	while (p[index].patient_ID != id)
	{
		if (index == size)
			break;

		index++;
	}

	if (index != size)
	{
		locWanted = index;
		found = true;
	}

	return found;
}