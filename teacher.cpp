#include "teacher.h"

Teacher::Teacher(){
	Full_name = "";
	Subject = "";
	//Groups = new string[1];
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
/*void Teacher::SetGroups(*inp,n){
	Groups = new string[n];
	for (i=0;i<n;i++){
	Groups[i]=inp[i];
	}
}
string* Teacher::GetGroups(){
	return Groups;
}
Teacher::~Teacher(){
	delete[] groups;
}*/
