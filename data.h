#ifndef DATA_H
#define DATA_H


class Data
{
public:
    Data();
    void Load(istream& in);
    void Save(ostream& out);
    ~Data();
};

#endif // DATA_H
