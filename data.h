#ifndef DATA_H
#define DATA_H
#include <fstream>
#include "teacher.h"
#include "student.h"
/**
\file
\brief Заголовочный файл с описанием классов
*/

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
/**
\public
*Конструктор класса Data
*/
    Data();
    Data(char *tfn, char *sfn);
    ~Data();
/**
\public
*Загрузка баз данных
*/
    void Load();
/**
\public
*Сохранение в базу данных преподавателей
*/
    void TeacherSave();
/**
\public
*Сохранение в базу данных студентов
*/
    void StudentSave();
/**
\public
*Считывает количество преподавателей
*/
    int GetCountTeachers();
/**
\public
*Считывает количество студентов
*/
    int GetCountStudents();
    Teacher GetTeacherById(int id);
    Student GetStudentById(int id);
/**
\public
*Добавление в базу данных преподавателей
*/    
    void AddTeacher(Teacher tc);
/**
\public
*Добавление в базу данных студентов
*/  
    void AddStudent(Student st);
/**
\public
*Поиск по базе данных преподавателей
*/
   
    int *SearchTeacher(int flag, string inp);
/**
\public
*Поиск по базе данных студентов
*/
    int *SearchStudent(int flag, string inp);
/**
\public
*Изменения в базе данных преподавателей 
*/
    void ChangeTeacherById(int id, Teacher tc);
/**
\public
*Изменения в базе данных студентов
*/
    void ChangeStudentById(int id, Student st);
/**
\public
*Удаление из базы данных преподавателей
*/
    void DeleteTeacher(int id);
    /**
\public
*Удаление из базы данных студентов
*/
    void DeleteStudent(int id);
};

#endif // DATA_H
