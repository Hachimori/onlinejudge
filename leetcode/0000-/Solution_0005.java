package leetcode;

public class Solution_0005 {
    
    public String longestPalindrome(String s) {
        
        int maxBgn = 0;
        int maxEnd = 0;
        
        for (int idx = 0; idx < s.length(); ++idx) {
            for (int toAdd = 0; toAdd < 2; ++toAdd) {
                int bgn = idx + 1;
                int end = idx - 1 + toAdd;
                
                while (0 <= bgn - 1 && end + 1 < s.length() && s.charAt(bgn - 1) == s.charAt(end + 1)) {
                    --bgn;
                    ++end;
                }
                
                if (maxEnd - maxBgn < end - bgn) {
                    maxEnd = end;
                    maxBgn = bgn;
                }
            }
        }
        
        return s.substring(maxBgn, maxEnd + 1);
    }
}
