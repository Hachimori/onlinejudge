package leetcode;

import java.util.HashMap;
import java.util.Map;
import java.util.Stack;

/**
 * Problem:
 *   https://leetcode.com/problems/valid-parentheses/
 * 
 * @author Ben Hachimori
 *
 */
public class Solution_0020 {
    
    /** Parenthesis of the same type **/
    private static final Map<Character, Character> MATCHING_CHAR_MAP = new HashMap<Character, Character>() {{
        put(')', '(');
        put('}', '{');
        put(']', '[');
    }};
    
    
    /**
     * 
     * @param s Input string consisting of '(', ')', '{', '}', '[', ']'.
     * @return True if each of parenthesis matches with the same type of parenthesis
     */
    public boolean isValid(String s) {
        
        Stack<Character> stack = new Stack<Character>();
        
        for (int i = 0; i < s.length(); ++i) {
            char ch = s.charAt(i);
            
            if (ch == '(' || ch == '{' || ch == '[') {
                stack.add(ch);
            }
            else {
                if (stack.size() > 0 && stack.peek() == MATCHING_CHAR_MAP.get(ch)) {
                    stack.pop();
                }
                else {
                    return false;
                }
            }
        }
        
        return stack.isEmpty();
    }
}
