#include "data.h"

Data::Data()
{

}
void Data::TeacherLoad(char*filename){
    file >> size;
    Teachers = new Teacher[size];
    for (int i = 0; i < size; i ++){
        file >> Teachers[i];
    }
void Data::StudentLoad(char*filename){
    file >> size;
    Stud = new Student[size];
    for (int i = 0; i < size; i ++){
        file >> Students[i];
    }
void Data::TeacherSave(char*filename){
    file.close();
    file.open(fileName);
    file << size;
    for (int i = 0; i < size; i++){
        file << Teachers[i];
    }
void Data::StudentSave(char*filename){
    file.close();
    file.open(fileName);
    file << size;
    for (int i = 0; i < size; i++){
        file << Studens[i];
    }
    file.close();
    file.open(fileName);
}
