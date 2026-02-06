#include <bits/stdc++.h>

class NQueens {
    int count = 0;
    int full_mask;
    std::vector<int> board;

public:
    void solve(int n) {
        count = 0;
        full_mask = (1 << n) - 1;
        board.resize(n);
        
        std::cout << "Finding all solutions for " << n << " queens...\n\n";
        solveRecursive(0, 0, 0, 0, n);
        
        std::cout << "\nTotal solutions found: " << count << std::endl;
    }

private:
    void printBoard(int n) {
        count++;
        std::cout << "Solution #" << count << ":" << std::endl;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i] == j) 
                    std::cout << " Q ";
                else 
                    std::cout << " . ";
            }
            std::cout << std::endl;
        }
        std::cout << "-----------------------" << std::endl;
    }

    void solveRecursive(int row, int cols, int ld, int rd, int n) {
        if (cols == full_mask) {
            printBoard(n);
            return;
        }

        //find all free positions in the current row
        int pos = full_mask & (~(cols | ld | rd));

        while (pos) {
            // Get the rightmost set bit (the first available column)
            int bit = pos & -pos;
            
            // Determining the column index for printing purposes
            int col_index = 0;
            int temp_bit = bit;
            while (temp_bit >>= 1) col_index++;
            
            board[row] = col_index; // Record position
            
            pos -= bit; // Mark this column as "tried"

            // Recurse: shift diagonals for the next row
            solveRecursive(row + 1, cols | bit, (ld | bit) << 1, (rd | bit) >> 1, n);
        }
    }
};

int main() {
    int n;
    std::cout << "Enter the size of the board (N): ";
    if (!(std::cin >> n) || n <= 0) {
        std::cout << "Please enter a valid positive integer." << std::endl;
        return 1;
    }

    NQueens solver;
    solver.solve(n);

    return 0;
}