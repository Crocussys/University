#include <iostream>
#include "menu.h"
#include "data.h"

using namespace std;

int main(int argc, char *argv[])
{
    if(argc < 3){
        cout << "Недостаточно аргументов: " << argc << " из 3" << endl;
        return 1;
    }
    Menu menu(argv[1], argv[2]);
    menu.start();
    return 0;
}
