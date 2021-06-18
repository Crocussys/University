#include <iostream>
#include "menu.h"

using namespace std;

void Menu::EnterStudent()
{
    string name;
    cout << "Введите ФИО" << endl << "> ";
    cin.ignore();
    getline(cin, name, '\n');
    int *arr = db.SearchStudent (1,name);
    int sizeArr = arr[0];
    bool flag = false;
    for (int i = 1; i <= sizeArr; i++) {
        int id = arr[i];
        class Student objSt=db.GetStudentById(id);
        while (true) {
            cout << "Вы " << objSt.GetFull_name() << "?" << endl << "> ";
            string answer;
            cin >> answer;
            if (answer == "д") {
                Student(id);
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

void Menu::Student(int id){
    int input;
    while (true) {
        cout << endl;
        cout << stMenu  << endl << endl << "> ";
        cin >> input;
        cout << endl;
        if (input==0) {
            bool result = false;
            while (!result){
                result = PrintStudent(id);
            }
        }
        else if (input==1) {
            cout << "До свидания" << endl;
            break;
        }
        else cout << miss << endl;
    }
}

void Menu::AddStudent()
{
    string name;
    string group;
    class Student objSt;
    cout << "Как вас зовут ?" << endl << "> ";
    getline(cin, name, '\n');
    objSt.SetFull_name(name);
    cout << endl;
    cout << "Какой номер у вашей группы ?" << endl << "> ";
    getline(cin, group, '\n');
    cout << endl;
    objSt.SetGroup(group);
    db.AddStudent(objSt);
    db.StudentSave();
    PrintStudent(db.GetCountStudents() - 1);
}

bool Menu::SearchStudent(int flag){
    if (flag < 0 || flag > 2){
        cout << "Ошибка флага." << endl;
        throw "Error flag";
    }
    string inputStr = "";
    if (flag == 1) cout << "Введите имя студента" << endl <<  "> ";
    if (flag == 2) cout << "Введите группу студента" << endl << "> ";
    if (flag > 0) {
        getline(cin, inputStr, '\n');
        cout << endl;
    }
    int *arr = db.SearchStudent(flag ,inputStr);
    int sizeArr = arr[0];
    if (sizeArr == 0) {
        cout << "Ничего не найдено" << endl;
        cout << endl;
        return true;
    }
    cout << endl;
    cout << "0. Выход" << endl;
    for (int i = 1; i <= sizeArr; i++) {
        class Student objSt = db.GetStudentById(arr[i]);
        cout << i << ". " << objSt.GetFull_name() << endl;
    }
    cout << endl;
    int input;
    cin >> input;
    if (input == 0) return true;
    else if (input > 0 && input <= sizeArr){
        bool result = false;
        while (!result){
            result = PrintStudent(arr[input]);
            cout << endl;
        }
        return true;
    }
    else cout << miss << endl;
    cout << endl;
    return false;
}

bool Menu::PrintStudent(int id)
{
    class Student objSt = db.GetStudentById(id);
    cout << objSt.GetFull_name() << endl;
    cout << objSt.GetGroup() << endl;
    for (int i = 0; i < objSt.GetCountSubjects(); i++) {
        cout << objSt.GetSubjectById(i) << ": ";
        for (int j = 0; j < objSt.GetCountGradesById(i); j++) {
            cout << objSt.GetGradeByIds(i, j) << " ";
        }
        cout << endl;
    }
    if (flag == 0) {
        cout << endl;
        cout << AdChangeSt << endl << endl << "> ";
        int input;
        cin >> input;
        cout << endl;
        cin.ignore();
        if (input == 0) {
            cout << "На какое имя поменять ?" << endl << "> ";
            string name;
            getline(cin, name, '\n');
            objSt.SetFull_name(name);
            db.ChangeStudentById(id, objSt);
        }
        else if (input == 1) {
            cout << "На какую группу поменять ?" << endl << "> ";
            string group;
            getline(cin, group, '\n');
            objSt.SetGroup(group);
            db.ChangeStudentById(id, objSt);
        }
        else if (input == 2) {
            cout << "Какой предмет добавить ?" << endl << "> ";
            string subject;
            getline(cin, subject, '\n');
            objSt.AddSubject(subject);
            db.ChangeStudentById(id, objSt);
        }
        else if (input == 3) {
            cout << "Какой предмет удалить ?" << endl << "> ";
            for (int i = 0; i < objSt.GetCountSubjects(); i++) {
                cout << i << ". " << objSt.GetSubjectById(i) << endl;
                for (int j = 0; j < objSt.GetCountGradesById(i); j++) {
                    cout << objSt.GetGradeByIds(i, j) << " ";
                }
            }
            int input;
            cin >> input;
            if (input < 0 || input >= objSt.GetCountSubjects()){
                cout << miss << endl;
                return false;
            }
            objSt.DeleteSubject(objSt.GetSubjectById(input));
            db.ChangeStudentById(id, objSt);
        }
        else if (input == 4) {
            AddGrade(id);
        }
        else if (input == 5) {
            DeleteGrade(id);
        }
        else if (input == 6) {
            db.DeleteStudent(id);
            return true;
        }
        else if (input == 7) {
            return true;
        }
        else cout << miss << endl;
    }
    else if (flag == 1) {
        cout << endl;
        cout << ThChangeSt << endl << endl << "> ";
        int input;
        cin >> input;
        cout << endl;
        cin.ignore();
        if (input==0) {
            AddGrade(id);
        }
        else if (input == 1) {
            DeleteGrade(id);
        }
        else if (input == 2) {
            return true;
        }
        else cout << miss << endl;
    }
    else if (flag == 2) {
        return true;
    }
    else {
        cout << miss << endl;
    }
    return false;
}

void Menu::AddGrade(int id){
    class Student objSt = db.GetStudentById(id);
    int grade;
    cout << "По какому предмету добавить оценку ?" << endl << "> ";
    for (int i = 0; i < objSt.GetCountSubjects(); i++) {
        cout << i << ". " << objSt.GetSubjectById(i) << ": ";
        for (int j = 0; j < objSt.GetCountGradesById(i); j++) {
            cout << objSt.GetGradeByIds(i, j) << " ";
        }
    }
    int indSub;
    cin >> indSub;
    if (indSub < 0 || indSub >= objSt.GetCountSubjects()){
        cout << miss << endl;
        return;
    }
    string subject = objSt.GetSubjectById(indSub);
    cout << "Какую оценку добавить ?" << endl << "> ";
    cin >> grade;
    objSt.AddGrade(subject, grade);
    db.ChangeStudentById(id, objSt);
}

void Menu::DeleteGrade(int id){
    class Student objSt = db.GetStudentById(id);
    cout << "По какому предмету удалить оценку ?" << endl << "> ";
    for (int i = 0; i < objSt.GetCountSubjects(); i++) {
        cout << i << ". " << objSt.GetSubjectById(i) << ": ";
        for (int j = 0; j < objSt.GetCountGradesById(i); j++) {
            cout << objSt.GetGradeByIds(i, j) << " ";
        }
    }
    int indSub;
    cin >> indSub;
    if (indSub < 0 || indSub >= objSt.GetCountSubjects()){
        cout << miss << endl;
        return;
    }
    string subject = objSt.GetSubjectById(indSub);
    cout << "" << endl;
    cout << subject << ": ";
    for (int j = 0; j < objSt.GetCountGradesById(indSub); j++) {
        cout << j << "." << objSt.GetGradeByIds(indSub, j) << " ";
    }
    int indGrad;
    cin >> indGrad;
    if (indGrad < 0 || indGrad >= objSt.GetCountGradesById(indSub)){
        cout << miss << endl;
        return;
    }
    objSt.DeleteGradeById(subject, indGrad);
    db.ChangeStudentById(id, objSt);
}
