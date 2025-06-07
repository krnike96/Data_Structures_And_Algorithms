#include <iostream>
#include <vector>
#include <string>
#include <limits>

using namespace std;

enum EntryStatus
{
    EMPTY,
    OCCUPIED,
    DELETED
};

struct HashTableEntry
{
    int key;
    string val;
    EntryStatus status;
    HashTableEntry() : key(-1), val(""), status(EMPTY) {}
};

class HashTable
{
private:
    int tableSize;
    vector<HashTableEntry> table;
    int count;
    int hashedIndex(int key)
    {
        return abs(key) % tableSize;
    }

public:
    HashTable(int size) : tableSize(size), table(tableSize), count(0) {}

    void insert(int key, const string &val);
    void remove(int key);
    string search(int key);
    void display();
    int getEntries();
    double getLoadFactor();
};

int main()
{
    int customSize;
    cout << "Enter custom size for the hash table : ";
    while (!(cin >> customSize) || customSize <= 0)
    {
        cout << "Invalid Size! Please enter a positive integer : ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    HashTable ht(customSize);
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
        while (!(cin >> ch))
        {
            cout << "Invalid input. Please enter a number: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        switch (ch)
        {
        case 1:
            cout << "Enter the Key : ";
            while (!(cin >> ch))
            {
                cout << "Invalid input. Please enter a number: ";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            cout << "Enter the String Value : ";
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            getline(cin, val);
            ht.insert(key, val);
            break;
        case 2:
            cout << "Enter the Key : ";
            while (!(cin >> key))
            {
                cout << "Invalid input! Please enter a positive integer : ";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            ht.remove(key);
            break;
        case 3:
            cout << "Enter the Key : ";
            while (!(cin >> key))
            {
                cout << "Invalid input! Please enter a positive integer : ";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            cout << "Result : " << ht.search(key) << endl;
            break;
        case 4:
            cout << "Current Element Count : " << ht.getEntries() << endl;
            break;
        case 5:
            cout << "Load Factor : " << ht.getLoadFactor() << endl;
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