#include <iostream>
#include <vector>
#include <utility>
using namespace std;

#define sizeTable 10
vector<pair<int, string>> hashTable[sizeTable];
int hashedIndex(int key)
{
    return key % sizeTable;
}

void insert(int key, string val)
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
    hashTable[i].push_back(make_pair(key, val));
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
    return "Key is not Found!";
}

void display()
{
    for (int i = 0; i < sizeTable; i++)
    {
        for (auto &keyVal : hashTable[i])
        {
            cout << "[" << keyVal.first << "-" << keyVal.second << "]" << endl;
        }
    }
}

int main()
{
    cout << "Hash Menu(Size : 10)" << endl;
    int ch, key;
    string val;
    while (true)
    {
        cout << "1.Insert" << endl;
        cout << "2.Search" << endl;
        cout << "3.Display" << endl;
        cout << "4.Exit" << endl;
        cout << "Enter your Choice : ";
        cin >> ch;
        switch (ch)
        {
        case 1:
            cout << "Enter the Key : ";
            cin >> key;
            cout << "Enter the String Value : ";
            cin >> val;
            insert(key, val);
            break;

        case 2:
            cout << "Enter the Search Key : ";
            cin >> key;
            cout << search(key) << endl;
            break;

        case 3:
            cout << "Hash Table Elements : " << endl;
            display();
            break;

        case 4:
            cout << "Exiting..." << endl;
            return 0;

        default:
            cout << "Invalid Choice!" << endl;
            break;
        }
    }
    return 0;
}