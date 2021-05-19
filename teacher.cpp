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
void Teacher::Set*Groups(string inp){
	*Groups = inp;
}
string Teacher::Get*Groups(){
	return *Groups;
}
void Teacher::print()
{
	cout<<endl;
	cout<<"Full name : "<<Full_name<<endl;
	cout<<"Subject : "<<Subject<<endl;
	cout<<"Groups : "<<*Groups<<endl;
	cout<<"****************"<<endl;
}
void Teacher::read(istream& listi)
{
	listi>>Full_name;
	listi>>Subject;
	listi>>*Groups;
}
void Muz::Printf(ostream& listo)
{
	listo<<Full_name<<" "<<Subject<<" "<<*Groups<<endl;
}
ostream& operator << (ostream& listo, Teacher& ms)
{
	ms.Printf(listo);
	return(listo);
}
istream& operator >> (istream& listi, Teacher& ms)
{
	ms.read(listi);
	return(listi);
}
Teacher::~Teacher(){
	delete[] groups;
}
