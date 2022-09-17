#include <string>
#include <iostream>
#include "Tree.h"

using namespace std;

int main()
{
    string a, b;
    int choise;
    int key;
    node* p = 0;
    string FIO;
    while (true)
    {
        cout << "What would you like to do?\n1-add 2-find 3-delete 4-print 5-switch max and min\n";
        cin >> choise;
        switch (choise)
        {
        case 1:
            cout << "Enter the key\n";
            cin >> key;
            cout << "Enter the name\n";
            cin >> FIO;
            p = insert(p, key, FIO);
            break;
        case 2:
            cout << "Enter the key\n";
            cin >> key;
            cout << search(p, key) <<endl;
            break;
        case 3:
            cout << "Enter the key\n";
            cin >> key;
            p = remove(p, key);
            break;
        case 4:
            print(p, 1);
            break;
        case 5:
            a = findmin(p)->FIO;
            b = findmax(p)->FIO;
            findmin(p)->FIO = b;
            findmax(p)->FIO = a;
            break;
        }
    }  
}