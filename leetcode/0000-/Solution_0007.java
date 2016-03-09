package leetcode;

public class Solution_0007 {
    
    public int reverse(int x) {
        
        try {
            int t = Integer.valueOf(new StringBuilder(String.valueOf(Math.abs(x))).reverse().toString());
            return x < 0 ? -t : t;
        }
        catch (NumberFormatException e) {
            return 0;
        }
    }
}
