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
			addStudent();
		}
		else if (input==1) {
			addTeacher();
		}
		else if (input==2) {
			//функция для поиска
		}
		else if (input==3) {
			//функция для поиска
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
        int *arr=SearchTeacher (1,name);
	int sizeArr=arr[0];
	Teacher objTh;
	for (int i=1; i<=sizeArr; i++) {
		objTh=GetTeacherById(arr[i]);
		while (true) {
			cout << "Вы " << objTh.GetFull_name() << "?" << endl;
			string answer;
			cin >> answer;
			if (answer=="д") {
				break;
			}
			else if (answer=="н") {
				teacher();
			}
			else cout << miss << endl;
		}
	}
	int input;
        while (true) {
                cout << thMEnu << endl;
                cin >> input;
                if (input==0) {

                }
                else if (input==1) {
                        cout << "До свидания" << endl;
                        break;
                }
		else cout << miss << endl;
	}
}

void Menu::student()
{
	string name;
	cout << "Введите ФИО" << endl;
        cin >> name;
	int input;
        while (true) {
                cout << stMEnu  << endl;
                cin >> input;
                if (input==0) {

                }
                else if (input==1) {
                        cout << "До свидания" << endl;
                        break;
                }
                else cout << miss << endl;
        }

        //proverka
}

void Menu::addTeacher()
{
	//ввести нужные данные для функции (предмет + фио)
	//данные внести в переменные
	//отправить в функцию
	/*
	string name;
	string subject;
	Teacher objTh;
	     спросить кто вы и запихнуть в функцию.
	
	*/
	db.AddTeacher(objTh);
}

void Menu::addStudent()
{
	//создать переменные
   	//ввести данные о студенте
	//отправить переменные в функцию
	db.AddStudent(objSt);
}

void Menu::SearchStudent()
{

}

void Menu::SearchTeacher()
{

}

