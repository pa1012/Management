#pragma once


#include<iostream>

using namespace std;

class Course {
private:
	string name;
	string ID;
	string lectureID;
	string startDate, endDate;
	string dayOfWeek;
	string start, end;
	string room;
	string inYear;
	int semester;
	string inClass;
public:
	void inputACourse(string id, string nam, string clas, string lecid, string year, int se, string startDt, string endDt, string inDay, string st, string en, string room);
	bool isMatched(Course C);
	string getID();
	int getSemester();
	string getYear();
};