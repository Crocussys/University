#include "data.h"

Data::Data()
{

}
void DataBase::Save(){
    file.close();
    file.open(FileName);
    file << size;
    for (int i = 0; i < size; i++){
        file << main[i];
    }
    file.close();
    file.open(FileName);
}
