/*!
\file
\brief Файл с описанием класса Student
*/
#ifndef STUDENT_H
#define STUDENT_H
#include <iostream>
using namespace std;
/*!
    \brief Объект студента

    Этот класс предназначен для изменения объектов типа Student
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
    /*!
    Конструктор класса
    */
	Student();
    /*!
    Деструктор класса
    */
    ~Student();
    /*!
    Возвращает ФИО студента
    \return ФИО студента
    */
    string GetFull_name();
    /*!
    Возвращает группу студента
    \return группа студента
    */
    string GetGroup();
    /*!
    Возвращает количество предметов у студента
    \return количество предметов
    */
    int GetCountSubjects();
    /*!
    Возвращает id предмета по его названию
    \param subject название предмета
    \return id предмета или -1, если такого предмета нет
    */
    int GetSubjectId(string subject);
    /*!
    Возвращает название предмета по его id
    \param id id предмета
    \return название предмета
    */
    string GetSubjectById(int id);
    /*!
    Возвращает количество оценок предмета по id предмета
    \param id id предмета
    \return количество оценок предмета
    */
    int GetCountGradesById(int id);
    /*!
    Возвращает оценку по её id и id предмета
    \param i id предмета
    \param j id оценки
    \return оценку
    */
    int GetGradeByIds(int i, int j);
    /*!
    Устанавливает ФИО студенту
    \param full_name Новое ФИО студента
    */
    void SetFull_name(string full_name);
    /*!
    Устанавливает группу студенту
    \param group Название новой группы студента
    */
    void SetGroup(string group);
    /*!
    Добавляет учебный предмет для студента
    \param subject Название предмета
    */
    void AddSubject(string subject);
    /*!
    Удаляет учебный предмет для студента
    \param subject Название предмета
    */
    void RemoveSubject(string subject);
    /*!
    Добавляет оценку по предмету
    \param subject Название предмета
    \param grade Оценка
    */
    void AddGrade(string subject, int grade);
    /*!
    Удаляет оценку по предмету и её id
    \param subject Название предмета
    \param id id оценки
    */
    void RemoveGradeById(string subject, int id);
    /*!
    Оператор вывода для корректной записи в базу данных
    > Используйте оператор ввода, чтобы считывание было корректным
    */
    friend ostream& operator<<(ostream& out, Student& st);
    /*!
    Оператор ввода для корректного считывания из базы данных
    > Используйте оператор вывода, чтобы запись была корректной
    */
    friend istream& operator>>(istream& in, Student& st);
};

#endif // STUDENT_H
