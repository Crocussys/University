#ifndef DATA_H
#define DATA_H


class Data
{
public:
    Data();
      void TeacherLoad(istream& in);
      void StudentLoad(istream& in);
      void TeacherSave(ostream& out);
      void StudentSave(ostream& out);
    ~Data();
};

#endif // DATA_H
