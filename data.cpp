#include "data.h"

Data::Data()
{
    Teacher* teachers;
    fstream teachers_file;
    char* teachers_file_name;
    int teachers_file_size;

    Student* students;
    fstream students_file;
    char* students_file_name;
    int students_file_size;
}
void Data::TeacherLoad(char*filename){
    file >> size;
    Teach = new Teacher[size];
    for (int i = 0; i < size; i ++){
        file >> Teach[i];
    }
void Data::StudentLoad(char*filename){
    file >> size;
    Stud = new Student[size];
    for (int i = 0; i < size; i ++){
        file >> Stud[i];
    }
void Data::TeacherSave(char*filename){
    file.close();
    file.open(fileName);
    file << size;
    for (int i = 0; i < size; i++){
        file << Teach[i];
    }
void Data::StudentSave(char*filename){
    file.close();
    file.open(fileName);
    file << size;
    for (int i = 0; i < size; i++){
        file << Srud[i];
    }
    file.close();
    file.open(fileName);
}
