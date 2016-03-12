package leetcode;

import java.util.Arrays;

/**
 * Problem:
 *   https://leetcode.com/problems/longest-common-prefix/
 * 
 * @author Ben Hachimori
 *
 */
public class Solution_0014 {
    
    /**
     * 
     * @param strs list of input strings
     * @return Longest Common Prefix of all given strings
     */
    public String longestCommonPrefix(String[] strs) {
        
        if (strs == null || strs.length == 0) {
            return "";
        }
        
        for (int lcp = 0; lcp < strs[0].length(); ++lcp) {
            for (int j = 0; j < strs.length; ++j) {
                if (lcp >= strs[j].length() || strs[0].charAt(lcp) != strs[j].charAt(lcp)) {
                    return strs[0].substring(0, lcp);
                }
            }
        }
        
        return strs[0];
    }
}
