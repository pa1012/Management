#include "Lecturer.h"
#include<vector>
#include"Convert.h"


using namespace std;

class School {
private:
	int numberOfLecturer;
	vector <Lecturer> lecturers;
	string name;
public:
	void inputLecturers(ArrOfAccount &Acc);
	void inputAdmins(ArrOfAccount &Acc);
	void clear();
};

