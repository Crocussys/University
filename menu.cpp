#include "menu.h"
#include <iostream>

using namespace std;

Menu::Menu()
{
    flag = -1;
}
Menu::Menu(char *tfn, char *sfn){
    flag = -1;
    Data db(tfn, sfn);
}
void Menu::start()
{
    db.Load();
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
			SearchStudentByName();
		}
		else if (input==3) {
			SearchTeacherByName();
		}
		else if (input==4) {
			SearchStudentByGroup();
		}
		else if (input==5) {
			SearchTeacherBySubject();
		}
		else if (input==6) {
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
        int *arr=db.SearchTeacher (1,name);
    int sizeArr=arr[0];
    Teacher objTh;
    for (int i=1; i<=sizeArr; i++) {
        objTh=db.GetTeacherById(arr[i]);
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
                cout << thMenu << endl;
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
	int *arr=db.SearchStudent (1,name);
    	int sizeArr=arr[0];
    	Student objSt;
    	for (int i=1; i<=sizeArr; i++) {
		objSt=db.GetStudentById(arr[i]);
		while (true) {
            		cout << "Вы " << objSt.GetFull_name() << "?" << endl;
            		string answer;
            		cin >> answer;
            		if (answer=="д") {
                		break;
            		}
            		else if (answer=="н") {
                		student();
            		}
            		else cout << miss << endl;
		}
        }

    int input;
        while (true) {
                cout << stMenu  << endl;
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
void Menu::addTeacher()
{
	string name;
   	string subject;
   	Teacher objTh;
	cout << "Как вас зовут ?" << endl;
	cin >> name;
	objTh.SetFull_name(name);
	cout << "Какой предмет вы ведёте ?" << endl;
	cin >> subject;
	objTh.SetSubject(subject);
	db.AddTeacher(objTh);
}

void Menu::addStudent()
{
	string name;
	string group;
	Student objSt;
	cout << "Как вас зовут ?" << endl;
	cin >> name;
	objSt.SetFull_name(name);
	cout << "Какой номер у вашей группы ?" << endl;
	cin >> group;
	objSt.SetGroup(group);
    	db.AddStudent(objSt);
}

void Menu::SearchStudentByName()
{
	string name;
	cout << "Введите имя студента" << endl;
	cin >> name;
	db.SearchStudent(1,name);
}

void Menu::SearchTeacherByName()
{
	string name;
	cout << "Введите имя преподавателя" << endl;
	cin >> name;
	db.SearchTeacher(1,name);
}

void Menu::SearchStudentByGroup()
{
	string group;
	cout << "Введите группу студента" << endl;
	cin >> group;
	db.SearchStudent(2,group);
}

void Menu::SearchTeacherBySubject()
{
	string subject;
	cout << "Введите предмет преподавателя" << endl;
	cin >> subject;
	db.SearchTeacher(2,subject);
}

<<<<<<< HEAD
void Menu::PrintStudent(Student objSt)
{
	cout << objSt.GetFull_name() << endl;
	cout << objSt.GetGroup() << endl;
	for (int i=0; i<objSt.GetCountSubjects(); i++) {
		cout << i << ". " << objSt.GetSubjectById(i) << ": ";
		for (int j=0; j<objSt.GetCountGradesById(i); j++) {
			cout << objSt.GetGradeByIds(i,j) << " ";
		}
		cout << endl;
	}
	while (true) {
		if (flag==0) {
			while (true) {
				cout << AdChangeSt << endl;
				//сделать меню для админа
			}
		}
		else if (flag==1) {
			while (true) {
				cout << ThChangeSt << endl;
				//сделать меню для учителя
			}
		}
		else if (flag==2) {
			string number;
			cout << "Для продолжения нажмите enter" << endl;
			cin >> number;
			break;
		}
		else {
			cout << miss << endl;
		}
	}
}

void Menu::PrintTeacher(Teacher objTh)
{
	cout << objTh.GetFull_name() << endl;
	cout << objTh.GetSubject() << endl;
	for (int i=0; i<objTh.GetCountGroupes(); i++) {
		cout << i << ". " << objTh.GetGroupById(i) << endl;
	}
}
=======

>>>>>>> 15182f8fc736309cfcaf317b03787f51a734214b
