#include "student.h"

Student::Student()
{	Full_name = "";
    Group = "";
    countSubjects = 0;
    countGrades = nullptr;
    Subjects = nullptr;
    Grades = nullptr;
}
Student::Student(string name, string group, int count_s){
    Full_name = name;
    Group = group;
    countSubjects = count_s;
    countGrades = new int[count_s];
    Subjects = new string[count_s];
    *Grades = new int[count_s];
    for (int i = 0; i < count_s; i++){
        Grades[i] = nullptr;
    }
}
void Student::SetFull_name(string inp){
	Full_name = inp;
}
string Student::GetFull_name(){
	return Full_name;
}
void Student::SetGroup(string inp){
	Group = inp;
}
string Student::GetGroup (){
	return Group;
}
void Student::print()
{
	cout<<endl;
	cout<<"Full name : "<<Full_name<<endl;
	cout<<"Group : "<<Group<<endl;
	cout<<"****************"<<endl;
}

void Student::addSubject(string subject){
    if (getSubjectId(subject) != -1){
        cout << "Такой предмет уже существует" << endl;
        return;
    }
    string *cashS = new string[countSubjects];
    int *cashC = new int[countSubjects];
    int **cashG = new int*[countSubjects];
    for (int i = 0; i < countSubjects; i++){
        cashS[i] = Subjects[i];
        cashC[i] = countGrades[i];
        cashG[i] = Grades[i];
    }
    delete [] Subjects;
    delete [] countGrades;
    delete [] Grades;
    countSubjects++;
    Subjects = new string[countSubjects];
    countGrades = new int[countSubjects];
    Grades = new int*[countSubjects];
    for (int i = 0; i < countSubjects; i++){
        Subjects[i] = cashS[i];
        countGrades[i] = cashC[i];
        Grades[i] = cashG[i];
    }
    Subjects[countSubjects - 1] = subject;
    countGrades[countSubjects - 1] = 0;
    Grades[countSubjects] = nullptr;
    delete [] cashS;
    delete [] cashC;
    delete [] cashG;
}

int Student::getSubjectId(string subject){
    for (int i = 0; i < countSubjects; i++){
        if(Subjects[i] == subject){
            return i;
        }
    }
    return -1;
}

void Student::removeSubject(string subject){
    int id = getSubjectId(subject);
    if (id == -1){
        cout << "Нет такого предмета" << endl;
        return;
    }
    string *cashS = new string[countSubjects];
    int *cashC = new int[countSubjects];
    int **cashG = new int*[countSubjects];
    for (int i = 0; i < countSubjects; i++){
        cashS[i] = Subjects[i];
        cashC[i] = countGrades[i];
        cashG[i] = Grades[i];
    }
    delete [] Subjects;
    delete [] countGrades;
    delete [] Grades;
    countSubjects--;
    Subjects = new string[countSubjects];
    countGrades = new int[countSubjects];
    Grades = new int*[countSubjects];
    bool flag = false;
    for (int i = 0; i < countSubjects; i++){
        if (i == id){
            flag = true;
            continue;
        }
        if (flag){
            Subjects[i] = cashS[i + 1];
            countGrades[i] = cashC[i + 1];
            Grades[i] = cashG[i + 1];
        }else {
            Subjects[i] = cashS[i];
            countGrades[i] = cashC[i];
            Grades[i] = cashG[i];
        }
    }
    delete [] cashS;
    delete [] cashC;
    delete [] cashG;
}
void Student::addGrade(string subject, int grade){
    int id = getSubjectId(subject);
    if (id == -1){
        cout << "Нет такого предмета" << endl;
        return;
    }
    int count = countGrades[id];
    int *grades = Grades[id];
    int *cash = new int[count];
    for (int i = 0; i < count; i++)
        cash[i] = grades[i];
    Grades[id] = nullptr;
    grades = nullptr;
    count++;
    countGrades[id] = count;
    grades = new int[count];
    for (int i = 0; i < count; i++)
        grades[i] = cash[i];
    grades[count - 1] = grade;
    Grades[id] = grades;
    delete [] cash;
    delete [] grades;
}

void Student::removeGradeById(string subject, int id){
    int sub_id = getSubjectId(subject);
    if (sub_id == -1){
        cout << "Нет такого предмета" << endl;
        return;
    }
    int count = countGrades[id];
    if (id < 0 || id >= count){
        cout << "Нет такого id" << endl;
        return;
    }
    int *grades = Grades[id];
    int *cash = new int[count];
    for (int i = 0; i < count; i++)
        cash[i] = grades[i];
    Grades[id] = nullptr;
    grades = nullptr;
    count--;
    countGrades[id] = count;
    grades = new int[count];
    bool flag = false;
    for (int i = 0; i < count; i++){
        if (i == id){
            flag = true;
            continue;
        }
        if (flag){
            grades[i] = cash[i + 1];
        }else {
            grades[i] = cash[i];
        }
    }
    Grades[id] = grades;
    delete [] cash;
    delete [] grades;
}
ostream& operator << (ostream& out, Student& st)
{
    out << st.GetFull_name() << "|";
    out << st.GetGroup() << "|";
 //   out << st.GetCountSubjects() << "|";
    for (int i = 0; i < st.countSubjects; i++)
        out << st.Subjects[i] << "|";
    for (int i = 0; i < st.countSubjects; i++){
        out << st.countGrades[i] << "|";
        for (int j = 0; j < st.countGrades[i]; j++)
            out << st.Grades[i][j] << "|";
    }
    out << endl;
    return out;
}
//istream& operator >> (istream& in, Student& st)
//{
//    string instr;
//    in >> instr;

//    return in;
//}
Student::~Student(){
    delete [] countGrades;
    delete [] Subjects;
    delete [] Grades;
}
