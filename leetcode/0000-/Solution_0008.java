package leetcode;

public class Solution_0008 {
    
    public int myAtoi(String str) {
        
        str = str.trim();
        
        boolean isNegative = false;
        int idx = 0;
        int ret = 0;
        
        if (str.isEmpty()) {
            return 0;
        }
        else if (str.charAt(idx) == '-') {
            isNegative = true;
            ++idx;
        }
        else if (str.charAt(idx) == '+') {
            ++idx;
        }
        
        while (idx < str.length()) {
            char ch = str.charAt(idx++);
            
            if (!Character.isDigit(ch)) {
                break;
            }
            
            if (ret > (Integer.MAX_VALUE - (ch - '0')) / 10) {
                return isNegative ? Integer.MIN_VALUE : Integer.MAX_VALUE;
            }
            
            ret = ret * 10 + (ch - '0');
        }
        
        return isNegative ? -ret : ret;
    }
}
