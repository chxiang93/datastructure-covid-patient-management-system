//PatientList.h
//Store the data of patient
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;
#ifndef PATIENTLIST_H
#define PATIENTLIST_H

struct PatientData
{
	string patient_name;
	int patient_ID;
	string patient_address;
	string patient_gender;
	int patient_age;
	string patient_confirmed_positive_date;
};

const int MAXSIZE = 100;

class PatientList
{
private:	
	int size;					//number of patient data
	PatientData p[MAXSIZE];		//array of patient data

public:
	int locWanted{ 0 };
	PatientList();
	int numberOfPatient();				//return the number of covid patient
	void addPatient();					//add a record of new covid patient
	void deletePatient();				//delete a record of covid patient
	void updatePatient();				//edit/update record of a covid patient
	void displayPatient();				//display data of all pcovid patient
	void displaySearchPatient();			//display the record of covid patient searched
	void sortAsc();						//sort the data of patient ascending
	void sortDesc();						//sort the data of patient descending
	bool searchPatient(int id);			//search a patient
};

#endif
