#include "teacher.h"

Teacher::Teacher(){
	Full_name = "";
	Subject = "";
    countGroups = 0;
    Groups = nullptr;
}
int Teacher::getGroupId(string group){
    for (int i = 0; i < countGroups; i++){
        if(Groups[i] == group){
            return i;
        }
    }
    return -1;
}
void Teacher::addGroup(string group){
    if (getGroupId(group) != -1){
        cout << "Такая группа уже существует" << endl;
        return;
    }
    int count = countGroups;
    string *cash = new string[count];
    for (int i = 0; i < count; i++)
        cash[i] = Groups[i];
    delete [] Groups;
    count++;
    countGroups = count;
    Groups = new string[count];
    for (int i = 0; i < count - 1; i++)
        Groups[i] = cash[i];
    Groups[count - 1] = group;
    delete [] cash;
}
void Teacher::removeGroup(string group){
     int id = getGroupId(group);
     if (id == -1){
         cout << "Нет такой группы" << endl;
         return;
     }
    int count = countGroups;
    string *cash = new string[count];
    for (int i = 0; i < count; i++)
        cash[i] = Groups[i];
    delete [] Groups;
    count--;
    countGroups = count;
    Groups = new string[count];
    bool flag = false;
    for (int i = 0; i < count; i++){
        if (i == id){
            flag = true;
            continue;
        }
        if (flag){
            Groups[i] = cash[i + 1];
        }else {
            Groups[i] = cash[i];
        }
    }
    delete [] cash;
}
void Teacher::SetFull_name(string inp){
	Full_name = inp;
}
string Teacher::GetFull_name(){
	return Full_name;
}
void Teacher::SetSubject(string inp){
	Subject = inp;
}
string Teacher::GetSubject(){
	return Subject;
}
ostream& operator << (ostream& out, Teacher& tc)
{
    int count_g = tc.countGroups;
    out << tc.GetFull_name() << "|";
    out << tc.GetSubject() << "|";
    out << count_g << "|";
    for (int i = 0; i < count_g; i++)
        out << tc.Groups[i] << "|";
    return out;
}
istream& operator >> (istream& in, Teacher& tc)
{
    string instr;
    int count_g = 0;
    getline(in, instr, '|');
    tc.SetFull_name(instr);
    getline(in, instr, '|');
    tc.SetSubject(instr);
    getline(in, instr, '|');
    count_g = stoi(instr);
    for (int i = 0; i < count_g; i++){
        getline(in, instr, '|');
        tc.addGroup(instr);
    }
    return in;
}
Teacher::~Teacher(){
	delete[] Groups;
}
int Teacher::GetCountGroupes(){
	return countGroups;
}
