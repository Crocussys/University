#ifndef DATA_H
#define DATA_H
#include <fstream>
#include "teacher.h"
#include "student.h"


class Data
{
private:
    Teacher* teachers;
    fstream teachers_file;
    char* teachers_file_name;
    int teachers_file_size;

    Student* students;
    fstream students_file;
    char* students_file_name;
    int students_file_size;
public:
    Data();
    Data(char *tfn, char *sfn);
    ~Data();

    void Load();
    void TeacherSave();
    void StudentSave();

    // Надо реализовать. По сути просто вернуть объект массива по индексу [id]
    Teacher GetTeacherById(int id);
    Student GetStudentById(int id);

    void AddTeacher(Teacher tc);
    void AddStudent(Student st);
    int *SearchTeacher(int flag, string inp);
    int *SearchStudent(int flag, string inp);

    // Надо реализовать. Просто вставить объект в массив по индексу.
    void ChangeTeacherById(int id, Teacher tc);
    void ChangeStudentById(int id, Student st);

    void DeleteTeacher(int id);
    void DeleteStudent(int id);
};

#endif // DATA_H
