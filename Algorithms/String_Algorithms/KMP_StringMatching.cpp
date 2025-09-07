#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<int> computeLPSDebug(const string& pattern) {
    int n = pattern.length();
    vector<int> lps(n, 0);
    int len = 0;
    int i = 1;
    
    cout << "Computing LPS for pattern: " << pattern << endl;
    cout << "Initial LPS: [";
    for (int j = 0; j < n; j++) cout << lps[j] << (j < n-1 ? "," : "");
    cout << "]" << endl << endl;
    
    while (i < n) {
        cout << "i=" << i << ", len=" << len << ": ";
        cout << "Compare pattern[" << i << "]='" << pattern[i] 
             << "' with pattern[" << len << "]='" << pattern[len] << "'";
        
        if (pattern[i] == pattern[len]) {
            len++;
            lps[i] = len;
            i++;
            cout << " => MATCH! len=" << len << ", lps[" << i-1 << "]=" << len << endl;
        } else {
            cout << " => MISMATCH" << endl;
            if (len != 0) {
                cout << "  Backtrack: len = lps[" << len-1 << "] = " << lps[len-1] << endl;
                len = lps[len - 1];
            } else {
                lps[i] = 0;
                i++;
                cout << "  Set lps[" << i-1 << "]=0" << endl;
            }
        }
        
        cout << "Current LPS: [";
        for (int j = 0; j < n; j++) cout << lps[j] << (j < n-1 ? "," : "");
        cout << "]" << endl << endl;
    }
    return lps;
}

int main() {
    cout << "Enter the Pattern to compute LPS table : ";
    string pattern;
    getline(cin,pattern);
    vector<int> lps = computeLPSDebug(pattern);
    
    cout << "Final LPS: [";
    for (int i = 0; i < lps.size(); i++) {
        cout << lps[i] << (i < lps.size()-1 ? "," : "");
    }
    cout << "]" << endl;
    
    return 0;
}