#include <iostream>
#include "menu.h"

using namespace std;

void Menu::EnterTeacher()
{
    string name;
    cout << "Введите ФИО" << endl << "> ";
    cin.ignore();
    getline(cin, name, '\n');
    int *arr = db.SearchTeacher (1,name);
    int sizeArr = arr[0];
    bool flag = false;
    for (int i = 1; i <= sizeArr; i++) {
        int id = arr[i];
        class Teacher objTh(db.GetTeacherById(id));
        while (true) {
            cout << "Вы " << objTh.GetFullName() << "?" << endl <<  "> ";
            string answer;
            cin >> answer;
            if (answer == "д") {
                Teacher(id);
                flag = true;
                break;
            }
            else if (answer == "н") {
                break;
            }
            else cout << miss << endl;
        }
        if (flag) break;
    }
}

void Menu::Teacher(int id){
    int input;
    while (true) {
        cout << endl;
        cout << thMenu << endl << endl << "> ";
        cin >> input;
        cout << endl;
        if (input == 0) {
            bool result = false;
            while (!result){
                result = PrintTeacher(id);
            }
        }
        else if (input == 1) {
            cout << "До свидания" << endl;
            break;
        }
        else cout << miss << endl;
    }
}

void Menu::AddTeacher()
{
    string name;
    string subject;
    class Teacher objTh;
    cout << "Как вас зовут ?" << endl << "> ";
    getline(cin, name, '\n');
    objTh.SetFullName(name);
    cout << endl;
    cout << "Какой предмет вы ведёте ?" << endl << "> ";
    getline(cin, subject, '\n');
    cout << endl;
    objTh.SetSubject(subject);
    db.AddTeacher(objTh);
    db.TeacherSave();
    PrintTeacher(db.GetCountTeachers() - 1);
}

bool Menu::SearchTeacher(int flag){
    if (flag < 0 || flag > 2){
        cout << "Ошибка флага." << endl;
        throw "Error flag";
    }
    string inputStr = "";
    if (flag == 1) cout << "Введите имя преподавателя" << endl << "> ";
    if (flag == 2) cout << "Введите предмет преподавателя" << endl << "> ";
    if (flag > 0) {
        getline(cin, inputStr, '\n');
        cout << endl;
    }
    int *arr = db.SearchTeacher(flag, inputStr);
    int sizeArr = arr[0];
    if (sizeArr == 0){
        cout << "Ничего не найдено" << endl;
        cout << endl;
        return true;
    }
    cout << "0. Выход" << endl;
    for (int i = 1; i <= sizeArr; i++) {
        class Teacher objTh(db.GetTeacherById(arr[i]));
        cout << i << ". " << objTh.GetFullName() << endl;
    }
    int input;
    cin >> input;
    if (input == 0) return true;
    else if (input > 0 && input <= sizeArr){
        bool result = false;
        while (!result){
            result = PrintTeacher(arr[input]);
        }
        return true;
    }
    else cout << miss << endl;
    return false;
}

bool Menu::PrintTeacher(int id)
{
    class Teacher objTh = db.GetTeacherById(id);
    cout << objTh.GetFullName() << endl;
    cout << objTh.GetSubject() << endl;
    for (int i = 0; i < objTh.GetCountGroupes(); i++) {
        cout << objTh.GetGroupById(i) << endl;
    }
    if (flag == 0) {
        cout << endl;
        cout << AdChangeTh << endl << endl << "> ";
        int input;
        cin >> input;
        cout << endl;
        cin.ignore();
        if (input == 0) {
            cout << "На какое имя поменять ?" << endl << "> ";
            string name;
            getline(cin, name, '\n');
            objTh.SetFullName(name);
            db.ChangeTeacherById(id, objTh);
        }
        else if (input == 1) {
            cout << "На какой предмет изменить ?" << endl << "> ";
            string subject;
            getline(cin, subject, '\n');
            objTh.SetSubject(subject);
            db.ChangeTeacherById(id, objTh);
        }
        else if (input == 2) {
            cout << "Какую группу добавить ?" << endl << "> ";
            string group;
            getline(cin, group, '\n');
            objTh.AddGroup(group);
            db.ChangeTeacherById(id, objTh);
        }
        else if (input == 3) {
            cout << "Какую группу удалить ?" << endl << "> ";
            for (int i = 0; i < objTh.GetCountGroupes(); i++) {
                cout << i << ". " << objTh.GetGroupById(i) << endl;
            }
            int input;
            cin >> input;
            if (input < 0 || input >= objTh.GetCountGroupes()){
                cout << miss << endl;
                return false;
            }
            objTh.DeleteGroup(objTh.GetGroupById(input));
            db.ChangeTeacherById(id, objTh);
        }
        else if (input == 4) {
            db.DeleteTeacher(id);
            return true;
        }
        else if (input == 5) {
            return true;
        }
        else cout << miss << endl;
    }
    else if (flag == 1) {
        return true;
    }
    else {
        cout << miss << endl;
    }
    return false;
}
