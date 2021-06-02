#include "teacher.h"

Teacher::Teacher(){
	Full_name = "";
	Subject = "";
    CountGroups = 0;
    Groups = nullptr;
}
Teacher::Teacher(const Teacher &tc){
    Full_name = tc.Full_name;
    Subject = tc.Subject;
    int count_g = tc.CountGroups;
    CountGroups = count_g;
    Groups = new string[count_g];
    for(int i = 0; i < count_g; i++){
        Groups[i] = tc.Groups[i];
    }
}
int Teacher::GetGroupId(string group){
    for (int i = 0; i < CountGroups; i++){
        if(Groups[i] == group){
            return i;
        }
    }
    return -1;
}
void Teacher::AddGroup(string group){
    if (GetGroupId(group) != -1){
        cout << "Такая группа уже существует" << endl;
        return;
    }
    int count = CountGroups;
    string *cash = new string[count];
    for (int i = 0; i < count; i++)
        cash[i] = Groups[i];
    delete [] Groups;
    count++;
    CountGroups = count;
    Groups = new string[count];
    for (int i = 0; i < count - 1; i++)
        Groups[i] = cash[i];
    Groups[count - 1] = group;
    delete [] cash;
}
void Teacher::RemoveGroup(string group){
     int id = GetGroupId(group);
     if (id == -1){
         cout << "Нет такой группы" << endl;
         return;
     }
    int count = CountGroups;
    string *cash = new string[count];
    for (int i = 0; i < count; i++)
        cash[i] = Groups[i];
    delete [] Groups;
    count--;
    CountGroups = count;
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
void Teacher::SetFullName(string inp){
	Full_name = inp;
}
string Teacher::GetFullName(){
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
    int count_g = tc.CountGroups;
    out << tc.GetFullName() << "|";
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
    tc.SetFullName(instr);
    getline(in, instr, '|');
    tc.SetSubject(instr);
    getline(in, instr, '|');
    count_g = stoi(instr);
    for (int i = 0; i < count_g; i++){
        getline(in, instr, '|');
        tc.AddGroup(instr);
    }
    return in;
}
int Teacher::GetCountGroupes(){
    return CountGroups;
}
string Teacher::GetGroupById(int id){
    return Groups[id];
}
Teacher::~Teacher(){
    delete[] Groups;
}
