package leetcode;

import java.util.ArrayList;
import java.util.List;

/**
 * Problem:
 *   https://leetcode.com/problems/generate-parentheses/
 * 
 * @author Ben Hachimori
 *
 */
public class Solution_0022 {
    
    /** Maximum n **/
    private static final int CAPACITY = 100;
    
    /** cache[n]: List of well-formed n parentheses **/
    private static List<List<String>> cache = new ArrayList<List<String>>() {{
        
        // initialize the cache with empty list
        for (int i = 0; i < CAPACITY; ++i) {
            add(new ArrayList<String>());
        }
    }};
    
    
    /**
     * 
     * @param n Input integer
     * @return List of well-formed n parenthesis
     */
    public List<String> generateParenthesis(int n) {
        
        // n is 0: cannot form parenthesis
        if (n == 0) {
            return new ArrayList<String>();
        }
        
        // generateParenthesis(n) is calculated before: use cache
        if (!cache.get(n).isEmpty()) {
            return cache.get(n);
        }
        
        List<String> ret = new ArrayList<String>();
        
        // n is 1: only one parenthesis can be formed
        if (n == 1) {
            ret.add("()");
            cache.set(1, ret);
            return ret;
        }
        
        // "(" + generateParenthesis(n - 1) + ")"
        for (String s : generateParenthesis(n - 1)) {
            ret.add("(" + s + ")");
        }
        
        // "(" + generateParenthesis(i) + ")" + generateParenthesis(n - i - 1)
        for (int i = 0; i + 1 < n; ++i) {
            List<String> leftS = generateParenthesis(i);
            List<String> rightS = generateParenthesis(n - i - 1);
            
            if (leftS.isEmpty()) leftS.add("");
            
            for (int j = 0; j < leftS.size(); ++j) {
                for (int k = 0; k < rightS.size(); ++k) {
                    ret.add("(" + leftS.get(j) + ")" + rightS.get(k));
                }
            }
        }
        
        // cache the result of generateParenthesis(n)
        cache.set(n, ret);
        
        return ret;
    }
}
