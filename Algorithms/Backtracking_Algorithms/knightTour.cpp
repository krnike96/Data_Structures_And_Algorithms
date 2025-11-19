//Knight Tour on Chess Board without Heuristics
#include <bits/stdc++.h>
using namespace std;

vector<int> movX = {1,-1,2,2,-1,1,-2,-2};
vector<int> movY = {2,2,1,-1,-2,-2,-1,1};

bool isValid(int r, int c, int n, vector<vector<int>>& cb){
    return (r >= 0 && r < n && c >= 0 && c < n && cb[r][c] == -1);
}
bool solve(int pos, int r, int c, int n, vector<vector<int>>& cb){
    if(pos == n * n){
        return true;
    }

    for(int i = 0; i < 8; i++){
        int newR = movX[i] + r;
        int newC = movY[i] + c;
        if(isValid(newR, newC, n, cb)){
            cb[newR][newC] = pos;
            if(solve(pos + 1, newR, newC, n, cb)){
                return true;
            }else{
                cb[newR][newC] = -1;
            }
        }
    }
    return false;
}

void printCb(vector<vector<int>>& cb){
    for(int i = 0; i < cb.size(); i++){
        for(int j = 0; j < cb.size(); j++){
            cout << setw(3) << cb[i][j];
        }
        cout << endl;
    }
}

int main(){
    int n;
    cout << "Enter the order of chess board(NxN) : ";
    cin >> n;

    vector<vector<int>> cb(n, vector<int>(n,-1));
    
    int r,c;
    cout << "Enter the position on Knight (RxC) : ";
    cin >> r >> c;

    int start = 0;
    
    cb[r][c] = start;

    if(solve(start + 1, r, c, n, cb)){
        printCb(cb);
    }else{
        cout << "Solution doesn't exist!";
    }

    return 0;
}