#ifndef STUDENT_H
#define STUDENT_H
#include <iostream>

using namespace std;

class Student
{
private:
	string Full_name;
	string Group;
	//string *Subjects;
	//int *Grades;
public:
	Student();

	void SetFull_name(string Full_name1);
	string GetFull_name();
	void SetGroup(string Group1);
	string GetGroup();
	//void SetSubjects(string *inp,int n);
	//string* GetSubjects();
	//void SetGrades(int *inp,int n);
	//int* GetGrades();
};

#endif // STUDENT_H
