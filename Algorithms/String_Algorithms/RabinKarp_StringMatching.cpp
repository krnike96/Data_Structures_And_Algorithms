#include <iostream>
#include <string>
#include <vector>
#define PRIME 101
using namespace std;

void rabinKarp(string &text, string &pattern)
{
    int count = 0;
    int n = text.length();
    int m = pattern.length();
    int pHash = 0;
    int tHash = 0;
    int h = 0;

    for (int i = 1; i < m - 1; i++)
    {
        h = (h * PRIME) % PRIME;
    }

    for (int i = 0; i < m; i++)
    {
        pHash = (pHash * PRIME + pattern[i]) % PRIME;
        tHash = (tHash * PRIME + text[i]) % PRIME;
    }

    for (int i = 0; i <= n - m; i++)
    {
        if (pHash == tHash)
        {
            bool match = true;
            for (int j = 0; j < m; j++)
            {
                if (text[i + j] != pattern[j])
                {
                    match = false;
                    break;
                }
            }

            if (match)
            {
                count++;
                cout << "Pattern found at position : " << i + 1 << endl;
            }
        }

        if (i < n - m)
        {
            tHash = (PRIME * (tHash - text[i] * h) + text[i + m]) % PRIME;

            if (tHash < 0)
            {
                tHash += PRIME;
            }
        }
    }
    cout << "Pattern Appearance : " << count << endl;
}

int main()
{
    string s, p;
    cout << "Enter the Text : ";
    cin >> s;

    cout << "Enter the Pattern : ";
    cin >> p;

    rabinKarp(s, p);

    return 0;
}