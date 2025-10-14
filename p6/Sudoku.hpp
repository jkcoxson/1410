// Jackson Coxson

#include <iostream>

class Sudoku {
  public:
    Sudoku() { clear(); }

    int  getValue(int i, int j) { return rows[i][j]; }

    bool solve(int row = 0, int col = 0) {
        // If we've reached the end of the grid
        if (row == 8 && col == 9) {
            return true;
        }

        // Move to the next row if we hit the end of this one
        if (col == 9) {
            row++;
            col = 0;
        }

        // Skip filled cells
        if (rows[row][col] != 0) {
            return solve(row, col + 1);
        }

        // Try placing numbers 1–9
        for (int num = 1; num <= 9; num++) {
            if (isSafe(row, col, num)) {
                rows[row][col] = num;

                if (solve(row, col + 1)) {
                    return true;
                }

                // Undo assignment (backtrack)
                rows[row][col] = 0;
            }
        }

        return false;
    }

    bool isSafe(int row, int col, int num) {
        // Check if num exist in the row
        for (int x = 0; x <= 8; x++) {
            if (rows[row][x] == num) {
                return false;
            }
        }

        // Check if num exist in the col
        for (int x = 0; x <= 8; x++) {
            if (rows[x][col] == num) {
                return false;
            }
        }

        // Check if num exist in the 3x3 sub-matrix
        int startRow = row - (row % 3), startCol = col - (col % 3);

        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (rows[i + startRow][j + startCol] == num) {
                    return false;
                }
            }
        }

        return true;
    }

    void printGrid() {
        for (auto& row : rows) {
            for (auto& digit : row) {
                std::cout << digit;
            }
            std::cout << std::endl;
        }
    }

    void clear() {
        for (auto& row : rows) {
            for (auto& digit : row) {
                digit = 0;
            }
        }
    }

    void set(int i, int j, int num) { rows[i][j] = num; }

  private:
    int rows[9][9];
};

std::istream& operator>>(std::istream& input, Sudoku& s) {
    // Reset the Sudoku grid
    s.clear();

    // Read 81 numbers (or characters) from the input stream
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            int value;
            if (!(input >> value)) {
                // If something goes wrong (e.g. fewer than 81 numbers), set failbit
                input.setstate(std::ios::failbit);
                return input;
            }

            // Optional: validate input (0–9)
            if (value < 0 || value > 9) {
                input.setstate(std::ios::failbit);
                return input;
            }

            s.set(i, j, value);
        }
    }

    return input;
}
