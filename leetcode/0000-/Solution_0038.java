package leetcode;

/**
 * Problem:
 *   https://leetcode.com/problems/count-and-say/
 * 
 * @author Ben Hachimori
 *
 */
public class Solution_0038 {
    
    /**
     * 
     * @param n n-th count-and-say sequence to be returned
     * @return n-th count-and-say sequence
     */
    public String countAndSay(int n) {
        
        StringBuilder prev = new StringBuilder("1");
        
        for (int i = 2; i <= n; ++i) {
            
            // Calculate i-th count-and-say sequence
            StringBuilder curr = new StringBuilder();
            
            for (int idx = 0; idx < prev.length(); ) {
                
                // Scan the same numbers
                int nextIdx = idx;
                while (nextIdx < prev.length() && prev.charAt(nextIdx) == prev.charAt(idx)) {
                    ++nextIdx;
                }
                
                // Append the number of appearance
                curr.append((char)('0' + (nextIdx - idx)));
                
                // Append current character 
                curr.append(prev.charAt(idx));
                
                idx = nextIdx;
            }
            
            prev = curr;
        }
        
        return prev.toString();
    }
}
