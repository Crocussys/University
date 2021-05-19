#include "teacher.h"

Teacher::Teacher(){
	Full_name = "";
	Subject = "";
    countGroups = 0;
    Groups = nullptr;
}
Teacher::Teacher(string name, string subject, int count_groups){
    Full_name = name;
    Subject = subject;
    countGroups = count_groups;
    Groups = new string[count_groups];
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
    for (int i = 0; i < count; i++)
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
void Teacher::print()
{
	cout<<endl;
	cout<<"Full name : "<<Full_name<<endl;
	cout<<"Subject : "<<Subject<<endl;
	cout<<"Groups : "<<*Groups<<endl;
	cout<<"****************"<<endl;
}
//void Teacher::read(istream& listi)
//{
//	listi>>Full_name;
//	listi>>Subject;
//	listi>>*Groups;
//}
//void Teacher::Printf(ostream& listo)
//{
//	listo<<Full_name<<" "<<Subject<<" "<<*Groups<<endl;
//}
//ostream& operator << (ostream& listo, Teacher& ms)
//{
//	ms.Printf(listo);
//	return(listo);
//}
//istream& operator >> (istream& listi, Teacher& ms)
//{
//	ms.read(listi);
//	return(listi);
//}
Teacher::~Teacher(){
	delete[] Groups;
}
