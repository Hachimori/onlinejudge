package leetcode;

public class Solution_0009 {
    
    public boolean isPalindrome(int x) {
        if (x < 0) return false;
        
        long revX = 0;
        for (int curX = x; curX > 0;) {
            revX = revX * 10 + curX % 10;
            curX /= 10;
        }
        
        return revX == x;
    }
}
