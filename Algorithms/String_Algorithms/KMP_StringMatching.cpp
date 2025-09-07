#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Function to compute LPS table
vector<int> computeLPS(const string &pattern)
{
    int n = pattern.length();
    vector<int> lps(n, 0);
    int len = 0;
    int i = 1;

    while (i < n)
    {
        if (pattern[i] == pattern[len])
        {
            len++;
            lps[i] = len;
            i++;
        }
        else
        {
            if (len != 0)
            {
                len = lps[len - 1];
            }
            else
            {
                lps[i] = 0;
                i++;
            }
        }
    }
    return lps;
}

// Function to find all occurrences using KMP algorithm
vector<int> kmpSearch(const string &text, const string &pattern)
{
    int n = text.length();
    int m = pattern.length();
    vector<int> occurrences;

    if (m == 0)
        return occurrences; // Empty pattern

    vector<int> lps = computeLPS(pattern);
    int i = 0;
    int j = 0;

    while (i < n)
    {
        if (pattern[j] == text[i])
        {
            i++;
            j++;
        }

        if (j == m)
        {
            occurrences.push_back(i - j);
            j = lps[j - 1];
        }
        else if (i < n && pattern[j] != text[i])
        {
            if (j != 0)
            {
                j = lps[j - 1];
            }
            else
            {
                i++;
            }
        }
    }

    return occurrences;
}

int main()
{
    string text, pattern;

    cout << "Enter the Text: ";
    getline(cin, text);

    cout << "Enter the Pattern: ";
    getline(cin, pattern);

    vector<int> occurrences = kmpSearch(text, pattern);

    cout << "\nResults:" << endl;
    cout << "Text: " << text << endl;
    cout << "Pattern: " << pattern << endl;

    if (occurrences.empty())
    {
        cout << "Pattern not found in the text." << endl;
    }
    else
    {
        cout << "Pattern found at " << occurrences.size() << " position(s): ";
        for (int idx : occurrences)
        {
            cout << idx << " ";
        }
        cout << endl;
    }

    return 0;
}