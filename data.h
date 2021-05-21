#ifndef DATA_H
#define DATA_H


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
      void TeacherLoad(char*filename);
      void StudentLoad(char*filename);
      void TeacherSave(char*filename);
      void StudentSave(char*filename);
    ~Data();
};

#endif // DATA_H
