#include <iostream>
#include <vector>
#include <list>
#include <utility>
#include <algorithm>

using namespace std;

class HashTable
{
private:
    const int tableSize = 11;       //Prime Numbered Size
    int count = 0;
    vector<list<pair<int, string>>> hashTable;

    int hashedIndex(int key);

public:
    HashTable();
    void insert(int key, const string &val);
    void remove(int key);
    string search(int key);
    void display();
    int getEntries();
    double getLoadFactor();
};

int main()
{
    HashTable ht;
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
            cin.ignore();
            getline(cin, val);
            ht.insert(key, val);
            break;
        case 2:
            cout << "Enter the Key : ";
            cin >> key;
            ht.remove(key);
            break;
        case 3:
            cout << "Enter the Key : ";
            cin >> key;
            cout << ht.search(key) << endl;
            break;
        case 4:
            cout << ht.getEntries() << endl;
            break;
        case 5:
            cout << ht.getLoadFactor() << endl;
            break;
        case 6:
            ht.display();
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