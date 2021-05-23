#include "data.h"

Data::Data()
{
    teachers = nullptr;
    teachers_file_name = nullptr;
    teachers_file_size = -1;
    students = nullptr;
    students_file_name = nullptr;
    students_file_size = -1;
}
Data::Data(char *tfn, char *sfn){
    teachers_file_name = tfn;
    students_file_name = sfn;
    teachers_file.open(tfn, ios::in);
    if (!teachers_file){
        cout << "Ошибка открытия файла." << endl;
        throw "Error openning file";
    }
    students_file.open(sfn, ios::in);
    if (!students_file){
        cout << "Ошибка открытия файла." << endl;
        throw "Error openning file";
    }
    teachers_file_size = -1;
    students_file_size = -1;
    teachers = nullptr;
    students = nullptr;
}
Data::~Data(){
    teachers_file.close();
    students_file.close();
    delete [] teachers;
    delete [] students;
}
void Data::Load(){
    int size;
    teachers_file >> size;
    teachers_file_size = size;
    teachers = new Teacher[size];
    for (int i = 0; i < size; i ++){
        teachers_file >> teachers[i];
    }
    students_file >> size;
    students_file_size = size;
    students = new Student[size];
    for (int i = 0; i < size; i ++){
        students_file >> students[i];
    }
}
void Data::TeacherSave(){
    teachers_file.close();
    teachers_file.open(teachers_file_name, ios::out|ios::trunc);
    teachers_file << teachers_file_size;
    for (int i = 0; i < teachers_file_size; i++){
        teachers_file << teachers[i] << endl;
    }
    teachers_file.close();
    teachers_file.open(teachers_file_name, ios::in);
}
void Data::StudentSave(){
    students_file.close();
    students_file.open(students_file_name, ios::out|ios::trunc);
    students_file << students_file_size;
    for (int i = 0; i < students_file_size; i++){
        students_file << students[i] << endl;
    }
    students_file.close();
    students_file.open(students_file_name, ios::in);
}
void Data::AddTeacher(Teacher tch){
    Teacher* tech = new Teacher[teachers_file_size];
    for (int i = 0; i < teachers_file_size; i++){
        tech[i] = temp[i];
    }
    delete [] temp;
    teachers_file_size++;
    temp = new Teacher[teachers_file_size];
    for (int i = 0; i < teachers_file_size - 1; i++){
        tch[i] = tech[i];
    }
    temp[teachers_file_size - 1] = tch;
    delete [] tech;
    TeacherSave(();
}
