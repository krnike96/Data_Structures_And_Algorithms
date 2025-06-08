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
    int key, count;
    string val;
    EntryStatus status;

    HashTableEntry() : key(-1), val(""), status(EMPTY) {}
};

class HashTable
{
private:
    int tableSize;
    int count;
    vector<HashTableEntry> table;

    int GCD(int a, int b)
    {
        while (b != 0)
        {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }

    int hashedIndex(int key)
    {
        return abs(key) % tableSize;
    }

    int doubleHash(int key)
    {
        if (tableSize <= 1)
            return 1;

        // Find largest number < tableSize that's coprime with tableSize
        int step = 1;
        for (int i = tableSize - 1; i > 1; i--)
        {
            if (GCD(i, tableSize) == 1)
            {
                step = i - (abs(key) % 1);
                if (step <= 0)
                {
                    step = i;
                }
                break;
            }
        }
        if (step <= 0 || GCD(step, tableSize) != 1)
        {
            step = 1;
        }
        return step;
    }

    int doubleHashingProbe(int key, int attempt)
    {
        int hash1 = hashedIndex(key);
        int hash2 = doubleHash(key);
        return (hash1 + attempt * hash2) % tableSize;
    }

public:
    HashTable(int size) : tableSize(size), table(tableSize), count(0) {}

    void insert(int key, const string &val)
    {
        int attempt = 0;
        int i = hashedIndex(key);
        while(table[i].status == OCCUPIED && table[i].key != key){
            attempt++;
            i = doubleHashingProbe(key,attempt);
            if(attempt >= tableSize){
                cout<<"Error : Hash Table is full for key : "<<key<<endl;
                return;
            }
        }

        if(table[i].status == OCCUPIED && table[i].key == key){
            cout<<"Key already exists, Updating to new value!"<<endl;
            table[i].val = val;
        }else{
            table[i].key = key;
            table[i].val = val;
            table[i].status = OCCUPIED;
            count++;
            cout<<"Inserted Key : "<<key<<" at index : "<<i<<" with probe attempts : "<<attempt<<endl;
        }
    }
    void remove(int key){
        int attempt = 0;
        int i = hashedIndex(key);

        while(table[i].status != EMPTY && attempt < tableSize){
            if(table[i].status == OCCUPIED && table[i].key == key){
                table[i].status = DELETED;
                count--;
                cout<<"Removed Key : "<<key<<" from index : "<<i<<endl;
                return;
            }
            attempt++;
            i = doubleHashingProbe(key,attempt);
        }
        cout<<"Key wasn't found!"<<endl;
    }

    string search(int key){
        int attempt = 0;
        int i = hashedIndex(key);

        while(table[i].status != EMPTY && attempt < tableSize){
            if(table[i].status == OCCUPIED && table[i].key == key){
                return table[i].val;
            }
            attempt++;
            i = doubleHashingProbe(key,attempt);
        }
        return "Key wasn't found!";
    }
    int display(){
        cout<<"=====Hash Table Content : Double Hashing Probe====="<<endl;
        for(int i = 0; i < tableSize; i++){
            if(table[i].status == OCCUPIED){
                cout<<"OCCUPIED : ["<<table[i].key<<"-"<<table[i].val<<"]";
            }else if(table[i].status == DELETED){
                cout<<"DELETED";
            }else{
                cout<<"EMPTY";
            }
            cout<<endl;
        }
    }
    int getEntries();
    double getLoadFactor();
};

int main()
{
    int customSize = 0;
    cout << "Enter custom size (Prime Number recommended) for the hash table : ";
    while (!(cin >> customSize) || customSize <= 0)
    {
        cout << "Invalid input, Please enter a positive integer : ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    HashTable ht(customSize);
    int key = 0;
    int ch = -1;
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
                cout << "Invalid input! Please enter a number : ";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            ht.remove(key);
            break;
        case 3:
            cout << "Enter the Key : ";
            while (!(cin >> key))
            {
                cout << "Invalid input! Please enter a number : ";
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