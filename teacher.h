/*!
\file
\brief Файл с описанием класса Teacher
*/
#ifndef TEACHER_H
#define TEACHER_H
#include <iostream>
using namespace std;
/*!
    \brief Объект преподавателя

    Этот класс предназначен для изменения объектов типа Teacher
*/
class Teacher
{
private:
    string Full_name;
    string Subject;
    string *Groups; 
    int CountGroups;
    int GetGroupId(string group);
public:
    /*!
    Конструктор класса
    */
    Teacher();
    /*!
    Деструктор класса
    */
    ~Teacher();
    /*!
    Конструктор копирования класса
    \param tc Объект преподавателя, который надо скопировать
    */
    Teacher(const Teacher &tc);
    /*!
    Возвращает ФИО преподавателя
    \return ФИО преподавателя
    */
    string GetFullName();
    /*!
    Возвращает предмет преподавателя
    \return предмет преподавателя
    */
    string GetSubject();
    /*!
    Возвращает количество групп у преподавателя
    \return количество групп
    */
    int GetCountGroupes();
    /*!
    Возвращает название группы по её id
    \param id id группы
    \return название группы
    */
    string GetGroupById(int id);
    /*!
    Устанавливает ФИО преподавателю
    \param full_name Новое ФИО преподавателя
    */
    void SetFullName(string full_name);
    /*!
    Устанавливает предмет преподавателю
    \param subject Название нового предмета преподавателя
    */
    void SetSubject(string subject);
    /*!
    Добавляет учебную группу студентов для преподавателя
    \param group Название группы
    */
    void AddGroup(string group);
    /*!
    Удаляет учебную группу студентов у преподавателя
    \param group Название группы
    */
    void RemoveGroup(string group);
    /*!
    Оператор вывода для корректной записи в базу данных
    > Используйте оператор ввода, чтобы считывание было корректным
    */
    friend ostream& operator<<(ostream& out, Teacher& tc);
    /*!
    Оператор ввода для корректного считывания из базы данных
    > Используйте оператор вывода, чтобы запись была корректной
    */
    friend istream& operator>>(istream& in, Teacher& tc);
};

#endif // TEACHER_H
