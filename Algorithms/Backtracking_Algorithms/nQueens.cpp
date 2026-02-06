#include <iostream>
#include <vector>

class NQueensClassic {
    int totalSolutions = 0;

public:
    void solve(int n) {
        // board[row][col] will be 1 if a queen is there, 0 otherwise
        std::vector<std::vector<int>> board(n, std::vector<int>(n, 0));
        backtrack(board, 0, n);
        std::cout << "\nTotal solutions: " << totalSolutions << std::endl;
    }

private:
    // Function to check if it's safe to place a queen at board[row][col]
    bool isSafe(std::vector<std::vector<int>>& board, int row, int col, int n) {
        for (int i = 0; i < row; i++) {
            if (board[i][col]) return false;
        }

        for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
            if (board[i][j]) return false;
        }

        for (int i = row, j = col; i >= 0 && j < n; i--, j++) {
            if (board[i][j]) return false;
        }

        return true;
    }

    void printBoard(const std::vector<std::vector<int>>& board, int n) {
        totalSolutions++;
        std::cout << "Solution #" << totalSolutions << ":\n";
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                std::cout << (board[i][j] ? " Q " : " . ");
            }
            std::cout << "\n";
        }
        std::cout << "-----------------------\n";
    }

    void backtrack(std::vector<std::vector<int>>& board, int row, int n) {
        if (row == n) {
            printBoard(board, n);
            return;
        }

        // Try placing a queen in each column of the current row
        for (int col = 0; col < n; col++) {
            if (isSafe(board, row, col, n)) {
                board[row][col] = 1;

                backtrack(board, row + 1, n);

                board[row][col] = 0;
            }
        }
    }
};

int main() {
    int n;
    std::cout << "Enter N: ";
    std::cin >> n;

    NQueensClassic solver;
    solver.solve(n);
    return 0;
}