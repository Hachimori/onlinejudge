package leetcode;

import java.util.ArrayList;
import java.util.List;

/**
 * Problem:
 *   https://leetcode.com/problems/letter-combinations-of-a-phone-number/
 * 
 * @author Ben Hachimori
 *
 */
public class Solution_0017 {
    
    /** mapping of digit to telephone letters **/
    private static final String[] DIGIT_TO_STRING = new String[] {
            "",     // 0
            "",     // 1
            "abc",  // 2
            "def",  // 3
            "ghi",  // 4
            "jkl",  // 5
            "mno",  // 6
            "pqrs", // 7
            "tuv",  // 8
            "wxyz", // 9
    };
    
    /**
     * 
     * @param digits Given input string
     * @return All possible combinations of telephone letter representations for given digits
     */
    public List<String> letterCombinations(String digits) {
        
        if (digits.isEmpty()) {
            return new ArrayList<String>();
        }
        
        List<String> ret = new ArrayList<String>();
        
        rec(0, new StringBuilder(), ret, digits);
        
        return ret;
    }
    
    /**
     * Recursively generates all combinations of telephone letter representations
     * 
     * @param idx Adding idx's letter 
     * @param sb Current string
     * @param ret Combinations of telephone letter representations 
     * @param digits Given input string
     */
    private void rec(int idx, StringBuilder sb, List<String> ret, String digits) {
        
        // finished adding digits.length() letters
        if (idx == digits.length()) {
            ret.add(sb.toString());
            return;
        }
        
        // add digits[idx]'s telephone letter
        int digit = digits.charAt(idx) - '0';
        for (int i = 0; i < DIGIT_TO_STRING[digit].length(); ++i) {
            sb.append(DIGIT_TO_STRING[digit].charAt(i));
            rec(idx + 1, sb, ret, digits);
            sb.deleteCharAt(idx);
        }
    }
}
