package leetcode;

/**
 * Problem:
 *   https://leetcode.com/problems/valid-sudoku/
 * 
 * @author Ben Hachimori
 *
 */
public class Solution_0036 {
    
    /**
     * 
     * @param board Partially filled sudoku board
     * @return true if board is valid, false otherwise
     */
    public boolean isValidSudoku(char[][] board) {
        
        
        for (int i = 0; i < 9; ++i) {
            
            boolean[] used = new boolean[10];
            
            // Check if there is the duplication of number within each row
            for (int j = 0; j < 9; ++j) {
                if (board[i][j] == '.') {
                    continue;
                }
                if (used[board[i][j] - '0']) {
                    return false;
                }
                used[board[i][j] - '0'] = true;
            }
            
            used = new boolean[10];
            
            // Check if there is the duplication of number within each column
            for (int j = 0; j < 9; ++j) {
                if (board[j][i] == '.') {
                    continue;
                }
                if (used[board[j][i] - '0']) {
                    return false;
                }
                used[board[j][i] - '0'] = true;
            }
        }
        
        // Check if there is the duplication of number within 3 x 3 cells
        for (int baseR = 0; baseR < 9; baseR += 3) {
            for (int baseC = 0; baseC < 9; baseC += 3) {
                boolean[] used = new boolean[10];
                
                for (int r = baseR; r < baseR + 3; ++r) {
                    for (int c = baseC; c < baseC + 3; ++c) {
                        if (board[r][c] == '.') {
                            continue;
                        }
                        if (used[board[r][c] - '0']) {
                            return false;
                        }
                        used[board[r][c] - '0'] = true;
                    }
                }
            }
        }
        
        return true;
    }
}
