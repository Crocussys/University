#ifndef STUDENT_H
#define STUDENT_H
#include <iostream>

using namespace std;

class Student
{
private:
	string Full_name;
	string Group;
	string *Subjects;
	int **Grades;
public:
	Student();
	~Student();
	void SetFull_name(string inp);
	string GetFull_name();
	void SetGroup(string inp);
	string GetGroup();
	Student(const string& Full_name,const int& Group);
	void read(istream& listi);
	void Printf(ostream& listo);
	void print();
	//void SetSubjects(string *inp,int n);
	//string* GetSubjects();
	//void SetGrades(int *inp,int n);
	//int* GetGrades();
};
ostream& operator<<(ostream& listo, Student& ms);
istream& operator>>(istream& listi, Student& ms);
#endif // STUDENT_H
