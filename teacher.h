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
    int countGroups;

    int getGroupId(string group);
public:
	Teacher();
//    Teacher(string name, string subject, int count_groups);
    ~Teacher();

	void Load(istream& in);
	void Save(ostream& out);
	void print();

    void addGroup(string group);
    void removeGroup(string group);

	void SetFull_name(string inp);
	string GetFull_name();
	void SetSubject(string inp);
    string GetSubject();
    int GetCountGroupes();

    friend ostream& operator<<(ostream& out, Teacher& tc);
    friend istream& operator>>(istream& in, Teacher& tc);
};

#endif // TEACHER_H
