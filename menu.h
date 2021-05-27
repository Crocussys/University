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
	const string adMenu = "0-Добавить студента\n1-Добавить преподавателя\n2-Просмотр студента по имени\n3-Просмотр преподавателя по имени\n"
				"4-Просмотр студента по группе\n5-Просмотр преподавателя по предмету\n6-Выход";
	const string thMenu = "0-Посмотреть группы\n1-Выход";
	const string stMenu = "0-Посмотреть оценки\n1-Выход";
	const string miss = "Вы ввели неверное значение";
	const string AdChangeSt = "0-Удалить\n1-Изменить имя\n2-Изменить группу\n3-Добавить предмет\n4-Убрать предмет\n5-Добавить оценку\n"
					"6-Убрать оценку\n7-Выход";
	const string ThChangeSt = "0-Добавить оценку\n1-Убрать оценку\n2-Выход";
	const string StChangeSt = "0-Выход";
	const string AdChangeTh = "0-Удалить преподавателя\n1-Изменить имя\n2-Изменить предмет\n3-Добавить группу\n4-Удалить группу\n5-Выход";
	void addTeacher();
	void addStudent();
	void admin();
	void teacher();
	void student();
	void start();
	void SearchStudentByName();
	void SearchTeacherByName();
	void SearchStudentByGroup();
	void SearchTeacherBySubject();
	void PrintStudent(Student objSt, int id);
	void PrintTeacher(Teacher objTh, int id);
};

#endif // MENU_H
