// Hashing with Collision Safety using Open Hashing/Separate Chaining.
#include <iostream>
#include <vector>
#include <list>
#include <utility>
#include <algorithm>

using namespace std;
const int tableSize = 11; // Prime Numbered Size
int count = 0;
vector<list<pair<int, string>>> hashTable(tableSize);

int hashedIndex(int);
void insert(int, const string &);
void remove(int);
string search(int);
void display();
int getEntries();

int main()
{
    cout << "Hash Table\n";
    int key, ch;
    string val;
    while (true)
    {
        cout << "===========Hash Table Menu===========" << endl;
        cout << "1.Insert" << endl;
        cout << "2.Remove" << endl;
        cout << "3.Search" << endl;
        cout << "4.Get Element Count" << endl;
        cout << "5.Get Load Factor" << endl;
        cout << "6.Display" << endl;
        cout << "7.Exit" << endl;
        cout << "Enter your Choice : ";
        cin >> ch;
        switch (ch)
        {
        case 1:
            cout << "Enter the Key : ";
            cin >> key;
            cout << "Enter the String Value : ";
            getline(cin, val);
            insert(key, val);
            break;
        case 2:
            cout << "Enter the Key : ";
            cin >> key;
            remove(key);
            break;
        case 3:
            cout << "Enter the Key : ";
            cin >> key;
            search(key);
            break;
        case 4:
            cout << getEntries() << endl;
            break;
        case 5:
            cout << getLoadFactor() << endl;
            break;
        case 6:
            display();
            break;
        case 7:
            cout << "Exiting..." << endl;
            return 0;
        default:
            cout << "Invalid Choice!" << endl;
            break;
        }
    }
    return 0;
}