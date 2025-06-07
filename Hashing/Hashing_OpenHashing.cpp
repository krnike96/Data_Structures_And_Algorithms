#include <iostream>
#include <vector>
#include <list>
#include <utility>
#include <algorithm>

using namespace std;

class HashTable
{
private:
    const int tableSize;
    int count = 0;
    vector<list<pair<int, string>>> hashTable;

    int hashedIndex(int key)
    {
        return abs(key) % tableSize;
    }

public:
    HashTable(int size) : tableSize(size), hashTable(size) {}

    void insert(int key, const string &val)
    {
        int i = hashedIndex(key);
        for (auto &keyVal : hashTable[i])
        {
            if (keyVal.first == key)
            {
                keyVal.second = val;
                return;
            }
        }
        hashTable[i].emplace_back(key, val);
        count++;
    }

    void remove(int key)
    {
        int i = hashedIndex(key);
        auto it = find_if(hashTable[i].begin(), hashTable[i].end(), [key](const pair<int, string> &p)
                          { return p.first == key; });
        if (it != hashTable[i].end())
        {
            hashTable[i].erase(it);
            count--;
            cout << "Key : " << key << " Removed!" << endl;
            return;
        }
        cout << "Key wasn't Found!" << endl;
    }
    string search(int key)
    {
        int i = hashedIndex(key);
        for (auto &keyVal : hashTable[i])
        {
            if (keyVal.first == key)
            {
                return keyVal.second;
            }
        }
        return "Key wasn't Found!";
    }
    void display()
    {
        for (int i = 0; i < tableSize; i++)
        {
            cout << "List - " << i << " : ";
            if (hashTable[i].empty())
            {
                cout << "Empty";
            }
            else
            {
                for (auto &keyVal : hashTable[i])
                {
                    cout << "[" << keyVal.first << "-" << keyVal.second << "]";
                }
            }
            cout << endl;
        }
    }

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
    int customSize;
    cout << "Enter hash table size (or 0 for default size 11): ";
    cin >> customSize;

    HashTable ht(customSize ? customSize : 11); // Prime Numbered Size
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