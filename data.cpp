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
Teacher Data::GetTeacherById(int id){
    if (id <teachers_file_size){
        return teachers[id];
        }
    }
Student Data::GetStudentById(int id){
    if (id <students_file_size){
        return students[id];
        }
    }


void Data::AddTeacher(Teacher tch){
    Teacher* tech = new Teacher[teachers_file_size];
    for (int i = 0; i < teachers_file_size; i++){
        tech[i] = teachers[i];
    }
    delete [] teachers;
    teachers_file_size++;
    teachers = new Teacher[teachers_file_size];
    for (int i = 0; i < teachers_file_size - 1; i++){
        teachers[i] = tech[i];
    }
    teachers[teachers_file_size - 1] = tch;
    delete [] tech;
    TeacherSave();
}
void Data::AddStudent(Student std){
    Student* stud = new Student[students_file_size];
    for (int i = 0; i < students_file_size; i++){
        stud[i] = students[i];
    }
    delete [] students;
    students_file_size++;
    students = new Student[students_file_size];
    for (int i = 0; i < teachers_file_size - 1; i++){
        students[i] = stud[i];
    }
    students[students_file_size - 1] = std;
    delete [] stud;
    StudentSave();
}
int *Data::SearchTeacher(int flag, string inp){
    if (flag < 0 || flag > 2){
        cout << "Ошибка флага." << endl;
        throw "Error flag";
    }
    int size = teachers_file_size;
    int count = 0;
    int *cash = new int[size];
    for (int i = 0; i < size; i++){
        Teacher tc = teachers[i];
        if (flag == 0 || (flag == 1 && !tc.GetFull_name().find(inp)) || (flag == 2 && !tc.GetSubject().find(inp))){
            cash[count] = i;
            count++;
        }
    }
    int *result = new int[count + 1];
    result[0] = count;
    for (int i = 1; i < count + 1; i++){
        result[i] = cash[i - 1];
    }
    delete [] cash;
    return result;
}
int *Data::SearchStudent(int flag, string inp){
    if (flag < 0 || flag > 2){
        cout << "Ошибка флага." << endl;
        throw "Error flag";
    }
    int size = students_file_size;
    int count = 0;
    int *cash = new int[size];
    for (int i = 0; i < size; i++){
        Student st = students[i];
        if (flag == 0 || (flag == 1 && !st.GetFull_name().find(inp)) || (flag == 2 && !st.GetGroup().find(inp))){
            cash[count] = i;
            count++;
        }
    }
    int *result = new int[count + 1];
    result[0] = count;
    for (int i = 1; i < count + 1; i++){
        result[i] = cash[i - 1];
    }
    delete [] cash;
    return result;
}
void ChangeTeacherById(int id, Teacher tc){
    Teacher* cash = new Teacher[teachers_file_size];
    for (int i = 0; i < teachers_file_size; i++){
        cash[i] = teachers[i];
    }
    delete [] teachers;
    teachers_file_size++;
    Teachers* teachers = new Teachers[teachers_file_size];
    for (int i = 0; i < teachers_file_size; i++){
        if (id==i){
            teachers[i]=tc[i];
        }esle{
            teachers[i] = cash[i];
        }        
    }
    delete [] cash;
    TeacherSave();

}
void ChangeStudentById(int id, Student st){
    Student* cash = new Student[students_file_size];
    for (int i = 0; i < students_file_size; i++){
        cash[i] = students[i];
    }
    delete [] students;
    students_file_size++;
    Student* students = new Student[students_file_size];
    for (int i = 0; i < students_file_size; i++){
        if (id==i){
            students[i]=st[i];
        }esle{
            students[i] = cash[i];
        }        
    }
    delete [] cash;
    StudentSave();

}
void Data::DeleteTeacher(int id){
    Teacher* cash = new Teacher[teachers_file_size];
    for (int i = 0; i < teachers_file_size; i++){
        cash[i] = teachers[i];
    }
    delete [] teachers;
    teachers_file_size--;
    Teachers* teachers = new Teachers[teachers_file_size];
    for (int i = 0; i < teachers_file_size; i++){
        if (i < id){
            teachers[i] = cash[i];
        }else{
            teachers[i] = cash[i + 1];
        }
    }
    delete [] cash;
    TeacherSave();
}
void Data::DeleteStudent(int id){
   Student* cach = new Student[students_file_size];
    for (int i = 0; i < students_file_size; i++){
        temp[i] = students[i];
    }
    delete [] students;
    students_file_size--;
    students = new Student[students_file_size];
    for (int i = 0; i < students_file_size; i++){
        if (i < id){
            students[i] = cash[i];
        }else{
            students[i] = cash[i + 1];
        }
    }
    delete [] cash;
    StudentSave();
}
