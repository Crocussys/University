#include "student.h"

Student::Student()
{	Full_name ="";
	Group ="";
	//subjects = new string[1];
	//grades = new string[1];
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
	delete [] grades;
}*/
