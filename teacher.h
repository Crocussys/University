#ifndef TEACHER_H
#define TEACHER_H
#include <iostream>

using namespace std;
/**
\file
\brief Файл с описанием класса преподавателя
*/
class Teacher
{
private:
    string Full_name;
    string Subject;
    string *Groups; 
    int countGroups;
    int getGroupId(string group);
public:
	/**
	\public
	*Конструктор класса Teacher
	*/
    Teacher();
    ~Teacher();
    /**
    \public
    *Добавляет группу в базу данных преподавателя 
    */
    void addGroup(string group);
     /**
    \public
    *Удаляет группу из базы данных преподавателя
    */
    void removeGroup(string group);
     /**
    \public
    *Считывает имя преподавателя
    */
    void SetFull_name(string inp);
    string GetFull_name();
     /**
    \public
    *Считывает предмет, который ведет данный преподаватель
    */
    void SetSubject(string inp);
    string GetSubject();
     /**
    \public
    *Считывает у каких групп ведет данный преподаватель
    */
    int GetCountGroupes();
    string GetGroupById(int id);

    friend ostream& operator<<(ostream& out, Teacher& tc);
    friend istream& operator>>(istream& in, Teacher& tc);
};

#endif // TEACHER_H
