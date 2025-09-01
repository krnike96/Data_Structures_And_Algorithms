#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int naiveAlgo(string &s, string &p)
{
    int sLen = s.length();
    int pLen = p.length();

    if (!sLen || !pLen)
        return -1;

    for (int i = 0; i <= sLen - pLen; i++)
    {
        string temp = s.substr(i, pLen);
        cout << temp << endl;
        if (temp == p && s.find(temp) != string::npos)
        {
            return i + 1;
        }
    }
    return -1;
}

int main()
{
    cout << "Enter the String/Text : ";
    string s;
    cin >> s;

    cout << "Enter the Pattern : ";
    string p;
    cin >> p;

    int index = naiveAlgo(s, p);

    if (index != -1)
        cout << "Pattern found at position : " << index;
    else
        cout << "Pattern not Found in the given String!";

    return 0;
}