#ifndef STUDENT_H
#define STUDENT_H
#include <iostream>

using namespace std;

class Student
{
private:
	string Full_name;
	string Group;

    int countSubjects;
    int *countGrades;

	string *Subjects;
	int **Grades;

public:
	Student();
    Student(string name, string group, int count_s);
    ~Student();

    void addSubject(string subject);
    void addGrade(string subject, int grade);
    void removeSubject(string subject);
    void removeGradeById(string subject, int id);

	void SetFull_name(string Full_name1);
	string GetFull_name();
    void SetGroup(string group);
	string GetGroup();
    int GetCountSubjects();

    string GetSubjectById(int id);
    int GetCountGradesById(int id);
    int GetGradeByIds(int i, int j);
    int getSubjectId(string subject);

    friend ostream& operator<<(ostream& out, Student& st);
    friend istream& operator>>(istream& in, Student& st);
};

#endif // STUDENT_H
