package leetcode;

public class Solution_0003 {
    
    public int lengthOfLongestSubstring(String s) {
        
        boolean[] exist = new boolean [256 * 256];
        
        int ans = 0;
        int L = 0;
        int R = 0;
        while (L < s.length()) {
            while (R < s.length() && !exist[s.charAt(R)]) {
                exist[s.charAt(R)] = true;
                ++R;
            }
            
            ans = Math.max(ans, R - L);
            
            exist[s.charAt(L)] = false;
            ++L;
        }
        
        return ans;
    }
}
