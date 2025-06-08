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
    int tableSize, count;
    vector<HashTableEntry> table;

    int hashedIndex(int key)
    {
        return abs(key) % tableSize;
    }
    int quadraticProbing(int key, int attempt)
    {
        return (hashedIndex(key) + attempt * attempt) % tableSize;
    }

public:
    HashTable(int size) : tableSize(size), table(tableSize), count(0) {}

    void insert(int key, const string &val)
    {
        int attempt = 0;
        int i = hashedIndex(key);

        while (table[i].status == OCCUPIED && table[i].key != key)
        {
            attempt++;
            i = quadraticProbing(key, attempt);
            if (i >= tableSize)
            {
                cout << "Error : Hash Table is full for key : " << key << endl;
                return;
            }
        }

        if (table[i].status == OCCUPIED && table[i].key == key)
        {
            cout << "Key already exists, Updating to new value!" << endl;
            table[i].val = val;
        }
        else
        {
            table[i].status = OCCUPIED;
            table[i].key = key;
            table[i].val = val;
            count++;
            cout << "Inserted Key : " << key << " at index : " << i << " with probe attempts : " << attempt << endl;
        }
    }

    void remove(int key)
    {
        int attempt = 0;
        int i = hashedIndex(key);

        while (table[i].status != EMPTY && attempt < tableSize)
        {
            if (table[i].status == OCCUPIED && table[i].key == key)
            {
                table[i].status = DELETED;
                count--;
                cout << "Removed key : " << key << " from index : " << i << endl;
                return;
            }
            attempt++;
            i = quadraticProbing(key, attempt);
        }
        cout << "Key wasn't found!" << endl;
    }
    
    string search(int key);
    void display();
    int getEntries()
    {
        return count;
    }
    double getLoadFactor()
    {
        return static_cast<double>(count) / tableSize;
    }
};

int main()
{
    int customSize = 0;
    cout << "Enter custom size for the hash table : ";
    while (!(cin >> customSize) || customSize <= 0)
    {
        cout << "Invalid input, Please enter a positive integer : ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    HashTable ht(customSize);
    int key = 0;
    ch = -1;
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
            while (!(cin >> key))
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