/*!
\file
\brief Файл с описанием класса Menu
*/
#ifndef MENU_H
#define MENU_H
#include <iostream>
#include "data.h"
using namespace std;
/*!
    \brief Класс для работы с пользователем

    Меню, позволяющее пользователю управлять приложением
*/
class Menu
{
private:
	int flag;
    Data db;

    const string enter = "Кем вы являетесь?\n0.Администратор\n1.Преподаватель\n2.Ученик";
    const string adMenu = "0.Добавить студента\n1.Добавить преподавателя\n2.Просмотр всех студентов\n"
                          "3.Просмотр студента по имени\n4.Просмотр студента по группе\n5.Просмотр всех преподавателей\n"
                          "6.Просмотр преподавателя по имени\n7.Просмотр преподавателя по предмету\n8.Выход";
    const string thMenu = "0.Посмотреть группы\n1.Выход";
    const string stMenu = "0.Посмотреть оценки\n1.Выход";
    const string miss = "Вы ввели неверное значение";
    const string AdChangeSt = "0.Изменить имя\n1.Изменить группу\n2.Добавить предмет\n3.Убрать предмет\n4.Добавить оценку\n"
                              "5.Убрать оценку\n6.Удалить\n7.Выход";
    const string ThChangeSt = "0.Добавить оценку\n1.Убрать оценку\n2.Выход";
    const string StChangeSt = "0.Выход";
    const string AdChangeTh = "0.Изменить имя\n1.Изменить предмет\n2.Добавить группу\n3.Удалить группу\n4.Удалить преподавателя\n"
                              "5.Выход";

    void Admin();

    void EnterStudent();
    void Student(int id);
    void AddStudent();
    bool SearchStudent(int flag);
    bool PrintStudent(int id);
    void AddGrade(int id);
    void DeleteGrade(int id);

    void EnterTeacher();
    void Teacher(int id);
    void AddTeacher();
    bool SearchTeacher(int flag);
    bool PrintTeacher(int id);
public:
    /*!
    Конструктор класса
    \param tfn Путь к файлу базы данных преподавателей
    \param sfn Путь к файлу базы данных студентов
    */
    Menu(char *tfn, char *sfn);
    /*!
    Запуск меню
    */
    void start();
};

#endif // MENU_H
