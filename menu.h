#ifndef MENU_H
#define MENU_H
#include <iostream>
#include "data.h"

using namespace std;

class Menu
{
private:
	int flag;
	Data db;
public:
    Menu();
    Menu(char *tfn, char *sfn);
    const string enter = "Кем вы являетесь?\n0-Администратор\n1-Преподаватель\n2-Ученик";
    const string adMenu = "0-Добавить студента\n1-Добавить преподавателя\n2-Просмотр студента\n3-Просмотр преподавателя\n4-Выход";
    const string thMenu = "0-Посмотреть группы\n1-Выход";
    const string stMenu = "0-Посмотреть оценки\n1-Выход";
	const string miss = "Вы ввели неверное значение";
	void addTeacher();
	void addStudent();
	void admin();
	void teacher();
	void student();
	void start();
	void SearchStudent();
	void SearchTeacher();
};

#endif // MENU_H
