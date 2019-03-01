#include"School.h"

void School::inputLecturers(ArrOfAccount &Acc) {
	stringstream str;
	str << "Data/" << name << "-Students.csv";
	string fileName = str.str();

	ifstream fin;

	fin.open(fileName.c_str());
	string no, id, lastName, firstName, gender, date;

	while (!fin.eof())
	{


		getline(fin, no, ',');

		getline(fin, id, ',');

		getline(fin, lastName, ',');
		;
		getline(fin, firstName, ',');

		getline(fin, gender, ',');

		getline(fin, date, '\n');

		int number;
		int sId;
		string pass;
		convertStringToInt(no, number);
		convertStringToInt(id, sId);
		convertDateToPass(date, pass);
		if (number != -1) {
			Lecturer S;
			if (gender[0] = 'M')
				S.inputALecturer(sId, lastName, firstName, 0, date);
			else
				S.inputALecturer(sId, lastName, firstName, 1, date);
			if (!Acc.isValid(id)) Acc.input(id, pass, 2);
			S.clear();
		}

	}
	fin.close();
}

void School::inputAdmins(ArrOfAccount &Acc) {
	stringstream str;
	str << "Data/" << name << "-Students.csv";
	string fileName = str.str();

	ifstream fin;

	fin.open(fileName.c_str());
	string no, id, lastName, firstName, gender, date;

	while (!fin.eof())
	{


		getline(fin, no, ',');

		getline(fin, id, ',');

		getline(fin, lastName, ',');
		;
		getline(fin, firstName, ',');

		getline(fin, gender, ',');

		getline(fin, date, '\n');

		int number;
		int sId;
		string pass;
		convertStringToInt(no, number);
		convertStringToInt(id, sId);
		convertDateToPass(date, pass);
		if (number != -1) {
			Lecturer S;
			if (gender[0] = 'M')
				S.inputALecturer(sId, lastName, firstName, 0, date);
			else
				S.inputALecturer(sId, lastName, firstName, 1, date);
			if (!Acc.isValid(id)) Acc.input(id, pass, 0);
			S.clear();
		}

	}
	fin.close();
}

void School::clear()
{

}