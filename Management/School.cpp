#include"School.h"

void School::loadLecturers(ArrOfAccount &Acc) {
	stringstream str;
	str << "Data/Lecturer.csv";
	string fileName = str.str();

	ifstream fin;

	fin.open(fileName.c_str());
	string no, id, lastName, firstName, gender, date;

	while (!fin.eof())
	{
		getline(fin, no, ',');
		getline(fin, id, ',');
		getline(fin, lastName, ',');
		getline(fin, firstName, ',');
		getline(fin, date, ',');
		getline(fin, gender, '\n');
		int number;
		int sId;
		string pass;
		convertStringToInt(no, number);
		convertStringToInt(id, sId);
		convertDateToPass(date, pass);
		int gen = 0;
		if (gender[0] == 'F') gen = 1;
		if (number != -1) {
			Lecturer S;
			if (gender[0] == 'M')
				S.inputALecturer(sId, lastName, firstName, 0, date);
			else
				S.inputALecturer(sId, lastName, firstName, 1, date);
			if (!Acc.isValid(id)) Acc.input(id, pass, 2,id,lastName,firstName,date,gen);
			lecturers.push_back(S);
			S.clear();
		}

	}
	fin.close();
}

void School::loadAdmins(ArrOfAccount &Acc) {
	stringstream str;
	str << "Data/Admin.csv";
	string fileName = str.str();

	ifstream fin;

	fin.open(fileName.c_str());
	string no, id, lastName, firstName, gender, date;

	while (!fin.eof())
	{

		getline(fin, no, ',');
		getline(fin, id, ',');
		getline(fin, lastName, ',');
		getline(fin, firstName, ',');
		getline(fin, date, ',');
		getline(fin, gender, '\n');
		

		int number;
		int sId;
		string pass;
		convertStringToInt(no, number);
		convertStringToInt(id, sId);
		convertDateToPass(date, pass);
		int gen = 0;
		if (gender[0] == 'F') gen = 1;
		if (number != -1) {
			Admin S;
			if (gender[0] == 'M')
				S.inputAAdmin(sId, lastName, firstName, 0, date);
			else
				S.inputAAdmin(sId, lastName, firstName, 1, date);
			if (!Acc.isValid(id)) Acc.input(id, pass, 0, id, lastName, firstName, date, gen);
			admins.push_back(S);
			S.clear();
		}

	}
	fin.close();
}

void School::clear()
{

}