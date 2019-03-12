#include"Class.h"

void Class::inputAClass(int n, string c, ArrOfAccount &Acc) {
	numberOfStudent = n;
	name = c;
	loadStudents(Acc);
}

void Class::loadStudents(ArrOfAccount &Acc) {
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
		getline(fin, firstName, ',');
		getline(fin, gender, ',');
		getline(fin, date, '\n');

		int number;
		int sId;
		string pass;
		convertStringToInt(no, number);
		convertStringToInt(id, sId);
		convertDateToPass(date, pass);
		int tmp = 0;
		if (gender[0] == 'F') tmp = 1;
		if (number != -1) {
			Student S;
			if (gender[0] == 'M')
				S.inputAStudent(sId, lastName, firstName, tmp, date);
			else
				S.inputAStudent(sId, lastName, firstName, tmp, date);
			if (!Acc.isValid(id)) Acc.input(id, pass, 1,id,lastName,firstName,date,tmp);
			students.push_back(S);
			S.clear();
		}

	}
	fin.close();
}

void Class::clear() {
	
}