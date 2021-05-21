#include "data.h"

Data::Data()
{

}
void DataBase::Load(){
    file >> size;
    main = new Product[size];
    for (int i = 0; i < size; i ++){
        file >> main[i];
    }
void Data::TeacherSave(){
    file.close();
    file.open(FileName);
    file << size;
    for (int i = 0; i < size; i++){
        file << main[i];
    }
    file.close();
    file.open(FileName);
}
