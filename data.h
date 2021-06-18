/*!
\file
\brief Файл с описанием класса Data
*/
#ifndef DATA_H
#define DATA_H
#include <fstream>
#include "teacher.h"
#include "student.h"
/*!
    \brief Класс управления базами данных

    Позволяет изменять базы данных, загружать их из файла или сохранять изменения
    в тот же файл
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
    /*!
    Конструктор класса
    \param tfn Путь к файлу базы данных преподавателей
    \param sfn Путь к файлу базы данных студентов
    \throw Error openning file
    */
    Data(char *tfn, char *sfn);
    /*!
    Деструктор класса
    */
    ~Data();
    /*!
    Загружает базы данных из указанных файлов.
    > Рекомендуется использовать сразу после инициализации класса
    */
    void Load();
    /*!
    Сохраняет изменения в файле для базы данных преподавателей
    */
    void TeacherSave();
    /*!
    Сохраняет изменения в файле для базы данных студентов
    */
    void StudentSave();
    /*!
    Возвращает количество преподавателей в базе данных
    \return Количество преподавателей в базе данных
    */
    int GetCountTeachers();
    /*!
    Возвращает количество студентов в базе данных
    \return Количество студентов в базе данных
    */
    int GetCountStudents();
    /*!
    Возвращает объект преподавателя по id (индексу массива)
    \param id id - индекс массива
    \return Объект преподавателя
    \throw Index error
    */
    Teacher GetTeacherById(int id);
    /*!
    Возвращает объект студента по id (индексу массива)
    \param id id - индекс массива
    \return Объект студента
    \throw Index error
    */
    Student GetStudentById(int id);
    /*!
    Добавляет преподавателя в базу данных
    \param tc Объект преподавателя, которого надо добавить в базу
    */
    void AddTeacher(Teacher tc);
    /*!
    Добавляет студента в базу данных
    \param st Объект студента, которого надо добавить в базу
    */
    void AddStudent(Student st);
    /*!
    Ищет преподавателя в базе данных
    \param flag 0 - вся база данных; 1 - поиск по имени; 2 - поиск по предмету
    \param inp Ввод для поиска (для flag = 0 можно передать пустую строку)
    \return Массив, первый элемент которого - количество последующих элементов,
            а далее индексы массива базы данных, элементы которых удовлетворяют условиям поиска.
    \throw Error flag
    */
    int *SearchTeacher(int flag, string inp);
    /*!
    Ищет студента в базе данных
    \param flag 0 - вся база данных; 1 - поиск по имени; 2 - поиск по группе
    \param inp Ввод для поиска (для flag = 0 можно передать пустую строку)
    \return Массив, первый элемент которого - количество последующих элементов,
            а далее индексы массива базы данных, элементы которых удовлетворяют условиям поиска.
    \throw Error flag
    */
    int *SearchStudent(int flag, string inp);
    /*!
    Изменяет базу данных преподавателей
    \param id id - индекс массива, относящийся к элементу, который следует заменить
    \param tc Объект преподавателя, на который надо заменить элемент
    */
    void ChangeTeacherById(int id, Teacher tc);
    /*!
    Изменяет базу данных студентов
    \param id id - индекс массива, относящийся к элементу, который следует заменить
    \param st Объект студента, на который надо заменить элемент
    */
    void ChangeStudentById(int id, Student st);
    /*!
    Удаляет преподавателя из базы данных
    \param id id - индекс массива, относящийся к элементу, который следует удалить
    */
    void DeleteTeacher(int id);
    /*!
    Удаляет студента из базы данных
    \param id id - индекс массива, относящийся к элементу, который следует удалить
    */
    void DeleteStudent(int id);
};

#endif // DATA_H
