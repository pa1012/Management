#pragma once

#include<iostream>
#include<fstream>
#include<sstream>
#include"ArrayOfAccount.h"

using namespace std;

class Admin {
private:
	long long ID;
	string lastName;
	string firstName;
	int gender;
	string date;
public:
	void inputAAdmin(int id, string last, string first, int gen, string d);
	void clear();
};


