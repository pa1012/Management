#pragma once

#include"Account.h"
#include<vector>

using namespace std;

class ArrOfAccount {
private:
	int n;
	vector <Account> A;
public:
	void loadAccount();
	bool isValid(string id);
	void input(string name, string pass, int role, string ID, string last, string first, string date, int gen);
	void saveAccount();
	int findUsername(string c);
	bool checkPassword(string c, int k);
	Account getAccount(int k);
	ArrOfAccount();
	void clear();
};