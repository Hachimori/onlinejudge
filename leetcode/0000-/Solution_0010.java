package leetcode;

public class Solution_0010 {
    
    boolean rec(int sIdx, int pIdx, String s, String p, int[][] dp) {
        
        if (sIdx == s.length() && pIdx == p.length()) return true;
        if (sIdx == s.length()) {
            for (int curPidx = pIdx; curPidx < p.length(); curPidx += 2) {
                if (!(curPidx + 1 < p.length() && p.charAt(curPidx + 1) == '*')) {
                    dp[sIdx][pIdx] = -1;
                    return false;
                }
            }
            return true;
        }
        if (pIdx == p.length()) return false;
        
        if (dp[sIdx][pIdx] != -1) return dp[sIdx][pIdx] > 0;
        
        int result = 0;
        if (pIdx + 1 < p.length() && p.charAt(pIdx + 1) == '*') {
            
            if (rec(sIdx, pIdx + 2, s, p, dp)) {
                result = 1;
            }
            
            for (int nexSidx = sIdx; nexSidx < s.length() && (s.charAt(nexSidx) == p.charAt(pIdx) || p.charAt(pIdx) == '.'); ++nexSidx) {
                if (rec(nexSidx + 1, pIdx + 2, s, p, dp)) {
                    result = 1;
                }
            }
        }
        else if (p.charAt(pIdx) == '.') {
            if (rec(sIdx + 1, pIdx + 1, s, p, dp)) {
                result = 1;
            }
        }
        else {
            if (s.charAt(sIdx) == p.charAt(pIdx) && rec(sIdx + 1, pIdx + 1, s, p, dp)) {
                result = 1;
            }
        }
        
        dp[sIdx][pIdx] = result;
        
        return result > 0;
    }
    
    public boolean isMatch(String s, String p) {
        
        int[][] dp = new int[s.length() + 1][p.length() + 1];
        for (int i = 0; i < dp.length; ++i) {
            for (int j = 0; j < dp[i].length; ++j) {
                dp[i][j] = -1;
            }
        }
        
        return rec(0, 0, s, p, dp);
    }
}
