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
    for (int i = 0; i < countSubjects - 1; i++){
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
    delete [] grades;
    grades = nullptr;
    count++;
    countGrades[id] = count;
    Grades[id] = new int[count];
    for (int i = 0; i < count - 1; i++)
        Grades[id][i] = cash[i];
    Grades[id][count - 1] = grade;
    delete [] cash;
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
    int count_s = st.countSubjects;
    out << st.GetFull_name() << "|";
    out << st.GetGroup() << "|";
    out << count_s << "|";
    for (int i = 0; i < count_s; i++){
        out << st.Subjects[i] << "|";
        int count_grs = st.countGrades[i];
        int *grs = st.Grades[i];
        out << count_grs << "|";
        for (int j = 0; j < count_grs; j++)
            out << grs[j] << "|";
    }
    return out;
}
istream& operator >> (istream& in, Student& st)
{
    int count_s;
    string instr;
    getline(in, instr, '|');
    st.SetFull_name(instr);
    getline(in, instr, '|');
    st.SetGroup(instr);
    getline(in, instr, '|');
    count_s = stoi(instr);
    for (int i = 0; i < count_s; i++){
        getline(in, instr, '|');
        string sub = instr;
        st.addSubject(instr);
        getline(in, instr, '|');
        int count_gr = stoi(instr);
        for (int j = 0; j < count_gr; j++){
            getline(in, instr, '|');
            st.addGrade(sub, stoi(instr));
        }
    }
    return in;
}
Student::~Student(){
    delete [] countGrades;
    delete [] Subjects;
    delete [] Grades;
}
int Student::GetCountSubjects(){
	return countSubjects;
}
