#pragma once
#include<iostream>
#include<fstream>
#include<sstream>
#include"ArrayOfCourse.h"

using namespace std;

class Account {
private:
	string id;
	string lastName, firstName;
	string username;
	string password;
	string doB;
	int role,gender;
public:
	void createAccount(const string name, string pass, int r, string ID, string last, string first, string date, int gen);
	bool checkUsername(string id);
	void output();
	bool isMatchName(string c);
	bool isMatchPass(string c);
	void tryOutput();
	void clear();
	int getRole();
};