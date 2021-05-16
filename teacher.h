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

	void SetFull_name(string inp);
	string GetFull_name();
	void SetSubject(string inp);
	string GetSubject();
	void SetGroups(int *inp,int n);
	string* GetGroups();
};

#endif // TEACHER_H
