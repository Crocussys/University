#ifndef TEACHER_H
#define TEACHER_H
#include <iostream>

using namespace std;

class Teacher
{
private:
	string Full_name;
	string Subject;
	string *Groups; 
public:
	Teacher();
	Teacher(const string& Full_name, const string& Subject, const string& *Groups);
	void read(istream& listi);
	void Printf(ostream& listo);
	void print();
	void SetFull_name(string inp);
	string GetFull_name();
	void SetSubject(string inp);
	string GetSubject();
	void SetGroups(int *inp,int n);
	string* GetGroups();
	~Teacher();
};
ostream& operator<<(ostream& listo, Teacher& ms);
istream& operator>>(istream& listi, Teacher& ms);
#endif // TEACHER_H
