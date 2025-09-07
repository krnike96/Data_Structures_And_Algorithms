#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Function to compute LPS with detailed debugging
vector<int> computeLPS(const string &pattern)
{
    int n = pattern.length();
    vector<int> lps(n, 0);
    int len = 0;
    int i = 1;

    cout << "=== LPS TABLE COMPUTATION ===" << endl;
    cout << "Pattern: " << pattern << endl;
    cout << "Initial LPS: [";
    for (int j = 0; j < n; j++)
        cout << lps[j] << (j < n - 1 ? "," : "");
    cout << "]" << endl
         << endl;

    while (i < n)
    {
        cout << "Step " << i << ": Compare pattern[" << i << "]='" << pattern[i]
             << "' with pattern[" << len << "]='" << pattern[len] << "'";

        if (pattern[i] == pattern[len])
        {
            len++;
            lps[i] = len;
            i++;
            cout << " => MATCH! len=" << len << ", lps[" << i - 1 << "]=" << len << endl;
        }
        else
        {
            cout << " => MISMATCH" << endl;
            if (len != 0)
            {
                cout << "  Backtrack: len = lps[" << len - 1 << "] = " << lps[len - 1] << endl;
                len = lps[len - 1];
            }
            else
            {
                lps[i] = 0;
                i++;
                cout << "  Set lps[" << i - 1 << "]=0" << endl;
            }
        }

        cout << "Current LPS: [";
        for (int j = 0; j < n; j++)
            cout << lps[j] << (j < n - 1 ? "," : "");
        cout << "]" << endl
             << endl;
    }
    return lps;
}

void kmpAlgo(const string &text, const string &pattern)
{
    int n = text.length();
    int m = pattern.length();

    vector<int> lps = computeLPS(pattern);
    vector<int> occurrences; // Store all occurrence indices

    cout << "Text: " << text << endl;
    cout << "Pattern: " << pattern << endl;
    cout << "LPS Table: [";
    for (int i = 0; i < m; i++)
        cout << lps[i] << (i < m - 1 ? "," : "");
    cout << "]" << endl
         << endl;

    int i = 0;
    int j = 0;
    int step = 1;

    while (i < n)
    {
        cout << "Step " << step++ << ": ";
        cout << "text[" << i << "]='" << text[i] << "' vs pattern[" << j << "]='" << pattern[j] << "'";

        if (pattern[j] == text[i])
        {
            cout << " => MATCH" << endl;

            // Display current state BEFORE moving pointers
            cout << "  Text:    ";
            for (int k = 0; k < n; k++)
            {
                if (k == i)
                    cout << "[" << text[k] << "]";
                else
                    cout << text[k];
            }
            cout << endl
                 << "  Pattern: ";
            for (int k = 0; k < m; k++)
            {
                if (k == j)
                    cout << "[" << pattern[k] << "]";
                else
                    cout << pattern[k];
            }
            cout << endl;

            i++;
            j++;
        }
        else
        {
            cout << " => MISMATCH" << endl;

            // Display current state
            cout << "  Text:    ";
            for (int k = 0; k < n; k++)
            {
                if (k == i)
                    cout << "[" << text[k] << "]";
                else
                    cout << text[k];
            }
            cout << endl
                 << "  Pattern: ";
            for (int k = 0; k < m; k++)
            {
                if (k == j)
                    cout << "[" << pattern[k] << "]";
                else
                    cout << pattern[k];
            }
            cout << endl;
        }

        if (j == m)
        {
            // Store the occurrence instead of printing immediately
            int foundIndex = i - j;
            occurrences.push_back(foundIndex);
            cout << "  Pattern found at index " << foundIndex << " (stored)" << endl;
            j = lps[j - 1];
        }
        else if (i < n && pattern[j] != text[i])
        {
            if (j != 0)
            {
                cout << "  Backtrack pattern: j = lps[" << j - 1 << "] = " << lps[j - 1] << endl;
                j = lps[j - 1];
            }
            else
            {
                cout << "  Move text pointer: i++" << endl;
                i++;
            }
        }
        cout << endl;
    }

    // Print all occurrences at the end
    cout << "=== FINAL RESULTS ===" << endl;
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

        // Optional: Show the text with matches highlighted
        cout << "Text with matches: ";
        int currentOccurrence = 0;
        for (int i = 0; i < n; i++)
        {
            if (currentOccurrence < occurrences.size() && i == occurrences[currentOccurrence])
            {
                cout << "[";
                for (int j = 0; j < m; j++)
                {
                    cout << text[i + j];
                }
                cout << "]";
                i += m - 1; // Skip the matched pattern
                currentOccurrence++;
            }
            else
            {
                cout << text[i];
            }
        }
        cout << endl;
    }
}

int main()
{
    cout << "Enter the Text : ";
    string text;
    getline(cin, text);

    cout << "Enter the Pattern : ";
    string pattern;
    getline(cin, pattern);

    kmpAlgo(text, pattern);

    return 0;
}