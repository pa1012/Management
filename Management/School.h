#pragma once

#include "Lecturer.h"
#include<vector>
#include"Convert.h"
#include"Admin.h"

using namespace std;

class School {
private:
	int numberOfLecturer;
	vector <Lecturer> lecturers;
	vector <Admin> admins;
	string name;
public:
	void loadLecturers(ArrOfAccount &Acc);
	void loadAdmins(ArrOfAccount &Acc);
	void clear();
};

