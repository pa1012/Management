#pragma once

#include<iostream>
#include<fstream>
#include<sstream>
#include"ArrayOfAccount.h"


using namespace std;

class Lecturer {
private:
	long long ID;
	string lastName;
	string firstName;
	int gender;
	string date;
	vector <Course> course;
public:
	void inputALecturer(int id, string last, string first, int gen, string d);
	void clear();
};

