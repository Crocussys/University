#include "student.h"

Student::Student()
{	Full_name ="";
	Group ="";
	Subjects =[];
	//Grades =[][];
}
Muz::Muz(const string& Full_name1,const int& Group1)
{
	Full_name=Full_name1;
	Group=Group1;
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
void Student::read(istream& listi)
{
	listi>>Full_name;
	listi>>Group;
}
void Student::Printf(ostream& listo)
{
	listo<<Full_name<<" "<<Group<<" "<<endl;
}
ostream& operator << (ostream& listo, Student& ms)
{
	ms.Printf(listo);
	return(listo);
}
istream& operator >> (istream& listi, Student& ms)
{
	ms.read(listi);
	return(listi);
}
/*void Student::SetSubjects(string *inp,int n){
	subjects = new string[n];
	for (i=0;i<n;i++){
	subjects[i]=inp[i];
	} 
}
string* Student::GetSubjects(){
	return subjects;
}
void Student::SetGrades(int *inp,int n){
	grades = new string[n];
	for (i=0;i<n;i++){
	grades[i]=inp[i];
	}
}
Student::~Student(){
	delete [] subjects;
	//delete [] grades;
}
