#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
    if(argc < 3){
        cout << "Недостаточно аргументов: " << argc << " из 3" << endl;
    }
    return 0;
}
