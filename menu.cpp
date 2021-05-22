#include "menu.h"
#include <iostream>

using namespace std;

Menu::Menu()
{
    flag = -1;
}
void Menu::start()
{
	cout << enter << endl;
	while (true) {
		cin >> flag;
		if (flag<0||flag>2) {
			cout << miss << endl;
		}
		else break;
	}
	if (flag==0) admin();
	else if (flag==1) teacher();
	else if (flag==2) student();
	else cout << miss << endl;
}

void Menu::admin()
{
	int input;
	while (true) {
		cout << adMenu << endl;
		cin >> input;
		if (input==0) {

		}
		else if (input==1) {
			addStudent();
		}
		else if (input==2) {
			addTeacher();
		}
		else if (input==3) {

		}
		else if (input==4) {
			cout << "До свидания" << endl;
			break;
		}
		else cout << miss << endl;
	}
}

void Menu::teacher()
{
	string name;
        cout << "Введите ФИО" << endl;
        cin >> name;
        //нужно сделать проверку
	// сделать такой же костяк. как у админа
}

void Menu::student()
{
	string name;
	cout << "Введите ФИО" << endl;
        cin >> name;
        //нужно сделать проверку
	// сделать такой же костяк. как у админа
}

void Menu::addTeacher()
{
	//ввести нужные данные для функции (предмет + фио)
	//данные внести в переменные
	//отправить в функцию
}

void Menu::addStudent()
{
	//создать переменные
   	//ввести данные о студенте
	//отправить переменные в функцию
}
