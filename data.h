#ifndef DATA_H
#define DATA_H


class Data
{
public:
    Data();
      void TeacherLoad();
      void StudentLoad();
      void TeacherSave();
      void StudentSave();
    Teacher* teachers;
    fstream teachers_file;
    char* teachers_file_name;
    int teachers_file_size;

    Student* students;
    fstream students_file;
    char* students_file_name;
    int students_file_size;
    ~Data();
};

#endif // DATA_H
