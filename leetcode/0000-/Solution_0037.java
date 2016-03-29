package leetcode;

/**
 * Problem:
 *   https://leetcode.com/problems/sudoku-solver/
 * 
 * @author Ben Hachimori
 *
 */
public class Solution_0037 {
    
    /**
     * Solves sudoku problem
     * 
     * @param board Partially filled sudoku board
     */
    public void solveSudoku(char[][] board) {
        
        // Used numbers
        boolean[][] row2used = new boolean[9][10];
        boolean[][] col2used = new boolean[9][10];
        boolean[][][] block2used = new boolean[3][3][10];
        
        for (int r = 0; r < 9; ++r) {
            for (int c = 0; c < 9; ++c) {
                if (board[r][c] == '.') {
                    continue;
                }
                row2used[r][board[r][c] - '0'] = true;
                col2used[c][board[r][c] - '0'] = true;
                block2used[r / 3][c / 3][board[r][c] - '0'] = true;
            }
        }
        
        
        rec(0, 0, board, row2used, col2used, block2used);
    }
    
    /**
     * Recursively solves sudoku problem
     * 
     * @param r Current row
     * @param c Current column
     * @param board Partially filled sudoku board
     * @param row2used Used numbers for each row
     * @param col2used Used numbers for each column
     * @param block2used Used numbers for each 3 x 3 cells
     * @return True if sudoku is solved, False otherwise
     */
    private boolean rec(int r, int c, char[][] board,
                        boolean[][] row2used, boolean[][] col2used, boolean[][][] block2used) {
        
        // Finished processing all cells, sudoku is solved
        if (r == 9) return true;
        
        // Finished processing one row, process next row
        if (c == 9) return rec(r + 1, 0, board, row2used, col2used, block2used);
        
        // The cell is filled already, process next column
        if (board[r][c] != '.') return rec(r, c + 1, board, row2used, col2used, block2used);
        
        for (int num = 1; num <= 9; ++num) {
            
            // Check duplication of number
            if (row2used[r][num]) continue;
            if (col2used[c][num]) continue;
            if (block2used[r / 3][c / 3][num]) continue;
            
            // Fill board[r][c] with num
            board[r][c] = (char)('0' + num);
            row2used[r][num] = true;
            col2used[c][num] = true;
            block2used[r / 3][c / 3][num] = true;
            
            // Process next column
            if (rec(r, c + 1, board, row2used, col2used, block2used)) {
                
                // If Sudoku is solved, return true
                return true;
            }
            
            // Empty board[r][c]
            row2used[r][num] = false;
            col2used[c][num] = false;
            block2used[r / 3][c / 3][num] = false;
            board[r][c] = '.';
        }
        
        
        return false;
    }
}
