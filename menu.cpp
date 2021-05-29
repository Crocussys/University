#include <iostream>
#include <string>
#include "menu.h"

using namespace std;

Menu::Menu()
{
    flag = -1;
}
Menu::Menu(char *tfn, char *sfn) : db(tfn, sfn){
    flag = -1;
    db.Load();
}
void Menu::start()
{
	while (true) {
        cout << enter << endl;
		cin >> flag;
        if (flag<0||flag>2) cout << miss << endl;
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
        cin.ignore();
		if (input==0) {
			addStudent();
		}
		else if (input==1) {
			addTeacher();
		}
		else if (input==2) {
            string name;
            cout << "Введите имя студента" << endl;
            getline(cin, name, '\n');
            int *arr = db.SearchStudent(1,name);
            int sizeArr=arr[0];
            if (sizeArr == 0){
                cout << "" << endl; //Дописать
                continue;
            }
            Student objSt;
            cout << "0. Выход" << endl;
            for (int i=1; i<=sizeArr; i++) {
                objSt=db.GetStudentById(arr[i]);
                cout << i << ". " << objSt.GetFull_name() << endl;
            }
            int input;
            while (true) {
                cin >> input;
                if (input == 0) break;
                else if (input > 0 && input <= sizeArr){
                    PrintStudent(arr[input]);
                    break;
                }
                else cout << miss << endl;
            }
		}
        else if (input==3) {
			string name;
            cout << "Введите имя преподавателя" << endl;
            getline(cin, name, '\n');
            int *arr = db.SearchTeacher(1,name);
			int sizeArr=arr[0];
            if (sizeArr == 0){
                cout << "" << endl; //Дописать
                continue;
            }
            Teacher objTh;
            cout << "0. Выход" << endl;
            for (int i=1; i<=sizeArr; i++) {
                 objTh=db.GetTeacherById(arr[i]);
                 cout << i << ". " << objTh.GetFull_name() << endl;
            }
            int input;
            while (true) {
                cin >> input;
                if (input == 0) break;
                else if (input > 0 && input <= sizeArr){
                    PrintTeacher(arr[input]);
                    break;
                }
                else cout << miss << endl;
            }
		}
        else if (input==4) {
			string group;
            cout << "Введите группу студента" << endl;
            getline(cin, group, '\n');
            int *arr=db.SearchStudent(2,group);
			int sizeArr=arr[0];
            if (sizeArr == 0){
                cout << "" << endl; //Дописать
                continue;
            }
            Student objSt;
            cout << "0. Выход" << endl;
            for (int i=1; i<=sizeArr; i++) {
                 objSt=db.GetStudentById(arr[i]);
                 cout << i << ". " << objSt.GetFull_name() << endl;
            }
            int input;
            while (true) {
                cin >> input;
                if (input == 0) break;
                else if (input > 0 && input <= sizeArr){
                    PrintStudent(arr[input]);
                    break;
                }
                else cout << miss << endl;
            }
		}
        else if (input==5) {
			string subject;
            cout << "Введите предмет преподавателя" << endl;
            getline(cin, subject, '\n');
            int *arr=db.SearchTeacher(2,subject);
			int sizeArr=arr[0];
            if (sizeArr == 0){
                cout << "" << endl; //Дописать
                continue;
            }
            Teacher objTh;
            cout << "0. Выход" << endl;
            for (int i=1; i<=sizeArr; i++) {
                 objTh=db.GetTeacherById(arr[i]);
                        cout << i << ". " << objTh.GetFull_name() << endl;
            }
            int input;
            while (true) {
                cin >> input;
                if (input == 0) break;
                else if (input > 0 && input <= sizeArr){
                    PrintTeacher(arr[input]);
                    break;
                }
                else cout << miss << endl;
            }
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
        getline(cin, name, '\n');
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
			for (int i=0; i<objTh.GetCountGroupes(); i++) {
				cout << i << ". " << objTh.GetGroupById(i) << endl;
			}
			cin >> input;
			int *arr=db.SearchStudent(2, objTh.GetGroupById(input));
			sizeArr=arr[0];
			Student objSt;
		    	for (int i=1; i<=sizeArr; i++) {
		        	objSt=db.GetStudentById(arr[i]);
				cout << arr[i] << ". " << objSt.GetFull_name() << endl;
			}
            cin >> input;
            PrintStudent(input);
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
        getline(cin, name, '\n');
	int *arr=db.SearchStudent (1,name);
    	int sizeArr=arr[0];
	int id;
    	Student objSt;
    	for (int i=1; i<=sizeArr; i++) {
		objSt=db.GetStudentById(arr[i]);
		while (true) {
            		cout << "Вы " << objSt.GetFull_name() << "?" << endl;
            		string answer;
            		cin >> answer;
            		if (answer=="д") {
				id=i;
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
                    PrintStudent(id);
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
    getline(cin, name, '\n');
	objTh.SetFull_name(name);
	cout << "Какой предмет вы ведёте ?" << endl;
    getline(cin, subject, '\n');
	objTh.SetSubject(subject);
	db.AddTeacher(objTh);
	db.TeacherSave();
    PrintTeacher(db.GetCountTeachers() - 1);
}

void Menu::addStudent()
{
	string name;
	string group;
	Student objSt;
	cout << "Как вас зовут ?" << endl;
    getline(cin, name, '\n');
	objSt.SetFull_name(name);
	cout << "Какой номер у вашей группы ?" << endl;
    getline(cin, group, '\n');
    objSt.SetGroup(group);
    db.AddStudent(objSt);
	db.StudentSave();
    PrintStudent(db.GetCountStudents() - 1);
}

void Menu::PrintStudent(int id)
{
    Student objSt = db.GetStudentById(id);
    cout << objSt.GetFull_name() << endl;
	cout << objSt.GetGroup() << endl;
	for (int i=0; i<objSt.GetCountSubjects(); i++) {
		cout << i << ". " << objSt.GetSubjectById(i) << ": ";
		for (int j=0; j<objSt.GetCountGradesById(i); j++) {
			cout << objSt.GetGradeByIds(i,j) << " ";
		}
		cout << endl;
	}
		if (flag==0) {
			while (true) {
				cout << AdChangeSt << endl;
				int input;
				cin >> input;
                cin.ignore();
				if (input==0) {
					db.DeleteStudent(id);
					break;
				}
				else if (input==1) {
					cout << "На какое имя поменять ?" << endl;
					string name;
                    getline(cin, name, '\n');
					objSt.SetFull_name(name);
                    db.ChangeStudentById(id, objSt);
				}
				else if (input==2) {
					cout << "На какую группу поменять ?" << endl;
					string group;
                    getline(cin, group, '\n');
					objSt.SetGroup(group);
                    db.ChangeStudentById(id, objSt);
                                }
				else if (input==3) {
					cout << "Какой предмет добавить ?" << endl;
					string subject;
                    getline(cin, subject, '\n');
					objSt.addSubject(subject);
                    db.ChangeStudentById(id, objSt);
                                }
				else if (input==4) {
					cout << "Какой предмет удалить ?" << endl;
					for (int i=0; i<objSt.GetCountSubjects(); i++) {
						cout << i << ". " << objSt.GetSubjectById(i) << endl;
					}
					int input;
					cin >> input;
					objSt.removeSubject(objSt.GetSubjectById(input));
                    db.ChangeStudentById(id, objSt);
                                }
				else if (input==5) {
					int grade;
					string subject;
					cout << "По какому предмету добавить оценку ?" << endl;
                    getline(cin, subject, '\n');
					cout << "Какую оценку добавить ?" << endl;
					cin >> grade;
					objSt.addGrade(subject, grade);
                    db.ChangeStudentById(id, objSt);
                                }
				else if (input==6) {
					string subject;
					cout << "По какому предмету удалить ?" << endl;
                    getline(cin, subject, '\n');
					int id = objSt.getSubjectId(subject);
					for (int i=0; i<objSt.GetCountGradesById(id); i++) {
						cout << i << ". " << objSt.GetGradeByIds(id, i) << endl;
					}
					int input;
					cin >> input;
					objSt.removeGradeById(subject, id);
                    db.ChangeStudentById(id, objSt);
                                }
				else if (input==7) {
					cout << "До свидания" << endl;
		                        break;
                                }
				else cout << miss << endl;
			}
		}
		else if (flag==1) {
			while (true) {
				cout << ThChangeSt << endl;
				int input;
				cin >> input;
                cin.ignore();
				if (input==0) {
					int grade;
                                        string subject;
                                        cout << "По какому предмету добавить оценку ?" << endl;
                                        getline(cin, subject, '\n');
                                        cout << "Какую оценку добавить ?" << endl;
                                        cin >> grade;
                                        objSt.addGrade(subject, grade);
                                        db.ChangeStudentById(id, objSt);
				}
				else if (input==1) {
					string subject;
                                        cout << "По какому предмету удалить ?" << endl;
                                        getline(cin, subject, '\n');
                                        int id = objSt.getSubjectId(subject);
                                        for (int i=0; i<objSt.GetCountGradesById(id); i++) {
                                                cout << i << ". " << objSt.GetGradeByIds(id, i) << endl;
                                        }
                                        int input;
                                        cin >> input;
                                        objSt.removeGradeById(subject, id);
                                        db.ChangeStudentById(id, objSt);
				}
				else if (input==2) {
					cout << "До свидания" << endl;
                                        break;
				}
				else cout << miss << endl;
			}
		}
		else if (flag==2) {
			string number;
			cout << "Для продолжения нажмите enter" << endl;
            getline(cin, number, '\n');
		}
		else {
			cout << miss << endl;
		}
}

void Menu::PrintTeacher(int id)
{
    Teacher objTh = db.GetTeacherById(id);
	cout << objTh.GetFull_name() << endl;
	cout << objTh.GetSubject() << endl;
	for (int i=0; i<objTh.GetCountGroupes(); i++) {
		cout << i << ". " << objTh.GetGroupById(i) << endl;
	}
                if (flag==0) {
                        while (true) {
                                cout << AdChangeTh << endl;
                                int input;
				cin >> input;
                cin.ignore();
				if (input==0) {
					db.DeleteTeacher(id);
					break;
				}
				else if (input==1) {
					cout << "На какое имя поменять ?" << endl;
                                        string name;
                                        getline(cin, name, '\n');
                                        objTh.SetFull_name(name);
                                        db.ChangeTeacherById(id, objTh);
                                }
                                else if (input==2) {
					cout << "На какой предмет изменить ?" << endl;
                                        string subject;
                                        getline(cin, subject, '\n');
                                        objTh.SetSubject(subject);
                                        db.ChangeTeacherById(id, objTh);
                                }
                                else if (input==3) {
					cout << "Какую группу добавить ?" << endl;
                                        string group;
                                        getline(cin, group, '\n');
                                        objTh.addGroup(group);
                                        db.ChangeTeacherById(id, objTh);
                                }
                                else if (input==4) {
					cout << "Какую группу удалить ?" << endl;
                                        for (int i=0; i<objTh.GetCountGroupes(); i++) {
                                                cout << i << ". " << objTh.GetGroupById(i) << endl;
                                        }
                                        int input;
                                        cin >> input;
                                        objTh.removeGroup(objTh.GetGroupById(input));
                                        db.ChangeTeacherById(id, objTh);
                                }
                                else if (input==5) {
					cout << "До свидания" << endl;
                                        break;
                                }
				else cout << miss << endl;
                        }
                }
                else if (flag==1) {
			string number;
                        cout << "Для продолжения нажмите enter" << endl;
                        getline(cin, number, '\n');
                }
                else {
                        cout << miss << endl;
                }
}
