#include "data.h"

Data::Data()
{

}
void Data::TeacherLoad(char*filename){
    teachers_file >> teachers_file_size;
    Teachers = new Teacher[size];
    for (int i = 0; i < teachers_file_size; i ++){
        teachers_file >> Teachers[i];
    }
void Data::StudentLoad(char*filename){
    students_file >> students_file_size;
    Students = new Student[size];
    for (int i = 0; i < students_file_size; i ++){
        students_file >> Students[i];
    }
void Data::TeacherSave(char*filename){
    file.close();
    file.open(teachers_file_name);
    teachers_file << teachers_file_size;
    for (int i = 0; i < teachers_file_size; i++){
        teachers_file << Teachers[i];
    }
void Data::StudentSave(char*filename){
    file.close();
    file.open(students_file_name);
    students_file << students_file_size;
    for (int i = 0; i < students_file_size; i++){
        students_file << Studens[i];
    }
    file.close();
    file.open(fileName);
}
