package leetcode;

import java.util.Stack;

/**
 * Problem:
 *   https://leetcode.com/problems/longest-valid-parentheses/
 * 
 * @author Ben Hachimori
 *
 */
public class Solution_0032 {
    
    /**
     * 
     * @param s Input of string, consisting of '(' and ')'
     * @return The maximum length of balanced parenthesis among s
     */
    public int longestValidParentheses(String s) {
       
        int ret = 0;
        Stack<Integer> stack = new Stack<Integer>();
        
        int[] dp = new int[s.length()];
        
        for (int i = 0; i < s.length(); ++i) {
            
            if (s.charAt(i) == '(') {
                // Push the index of '('
                stack.push(i);
            }
            else if (!stack.isEmpty()) {
                // Get the index of last '(' 
                int bgnIndex = stack.pop();
                
                // (i - bgnIndex + 1)
                // ==> s[bgnIndex ... i] holds balanced parenthesis
                
                // (bgnIndex > 0 ? dp[bgnIndex - 1] : 0);
                // ==> To concatenate with current balanced parenthesis,
                //     get the length of balanced parenthesis just before bgnIndex - 1
                int leng = (i - bgnIndex + 1) + (bgnIndex > 0 ? dp[bgnIndex - 1] : 0);
                
                ret = Math.max(ret, dp[i] = leng);
            }
        }
        
        return ret;
    }
}
