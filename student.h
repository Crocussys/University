#ifndef STUDENT_H
#define STUDENT_H
#include <iostream>

using namespace std;
/**
\file
\brief Файл с описанием класса студента
*/
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
     /**
     \public
     *Конструктор класса Student
     */
	Student();
    Student(string name, string group, int count_s);
    ~Student();
    /**
    \public
    *Добавление предметов в базу данных студента
    */
    void addSubject(string subject);
    /**
    \public
    *Добавление оценки студенту
    */
    void addGrade(string subject, int grade);
    /**
    \public
    *Удаление предмета из базы данных студента
    */
    void removeSubject(string subject);
    /**
    \public
    *Удаление оценки студента
    */
    void removeGradeById(string subject, int id);
    /**
    \public
    *Считывание имени студента из базы данных
    */
    void SetFull_name(string Full_name1);
	string GetFull_name();
    /**
    \public
    *Считывание группы студента из базы данных
    */
    void SetGroup(string group);
	string GetGroup();
    /**
    \public
    *Считывает количество предметов у студента
    */
    int GetCountSubjects();
        string GetSubjectById(int id);
    /**
    \public
    *Считывает количество оценок у студента
    */
    int GetCountGradesById(int id);
    /**
    \public
    *Считывает какие оценки есть у студента
    */
    int GetGradeByIds(int i, int j);
    /**
    \public
    *Считывает каким предметам обучается данный студент
    */
    int getSubjectId(string subject);

    friend ostream& operator<<(ostream& out, Student& st);
    friend istream& operator>>(istream& in, Student& st);
};

#endif // STUDENT_H
