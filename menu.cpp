#include <iostream>
#include "menu.h"

using namespace std;

Menu::Menu(char *tfn, char *sfn) : db(tfn, sfn){
    flag = -1;
    db.Load();
}
void Menu::start()
{
	while (true) {
        cout << enter << endl << endl << "> ";
		cin >> flag;
		cout << endl;
        if (flag<0||flag>2) cout << miss << endl;
		else break;
	}
    if (flag==0) Admin();
    else if (flag==1) EnterTeacher();
    else if (flag==2) EnterStudent();
	else cout << miss << endl;
}

void Menu::Admin()
{
    int input;
    while (true) {
        cout << adMenu << endl << endl << "> ";
        cin >> input;
        cout << endl;
        cin.ignore();
        if (input==0) {
            AddStudent();
        }
        else if (input==1) {
            AddTeacher();
        }
        else if (input==2) {
            bool result = false;
            while (!result){
                result = SearchStudent(0);
            }
        }
        else if (input==3) {
            bool result = false;
            while (!result){
                result = SearchStudent(1);
            }
        }
        else if (input==4) {
            bool result = false;
            while (!result){
                result = SearchStudent(2);
            }
        }
        else if (input==5) {
            bool result = false;
            while (!result){
                result = SearchTeacher(0);
            }
        }
        else if (input==6) {
            bool result = false;
            while (!result){
                result = SearchTeacher(1);
            }
        }
        else if (input==7) {
            bool result = false;
            while (!result){
                result = SearchTeacher(2);
            }
        }
        else if (input==8) {
            cout << "До свидания" << endl;
            break;
        }
        else cout << miss << endl;
    }
}
