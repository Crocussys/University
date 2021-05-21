#include "data.h"

Data::Data()
{

}
void Data::TeacherLoad(){
    file >> size;
    Teach = new Teacher[size];
    for (int i = 0; i < size; i ++){
        file >> Teach[i];
    }
void Data::StudentLoad(){
    file >> size;
    Stud = new Student[size];
    for (int i = 0; i < size; i ++){
        file >> Stud[i];
    }
void Data::TeacherSave(){
    file.close();
    file.open(FileName);
    file << size;
    for (int i = 0; i < size; i++){
        file << Teach[i];
    }
void Data::StudentSave(){
    file.close();
    file.open(FileName);
    file << size;
    for (int i = 0; i < size; i++){
        file << Srud[i];
    }
    file.close();
    file.open(FileName);
}
