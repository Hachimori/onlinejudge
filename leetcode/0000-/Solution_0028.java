package leetcode;

/**
 * Problem:
 *   https://leetcode.com/problems/implement-strstr/
 * 
 * @author Ben Hachimori
 *
 */
public class Solution_0028 {
    
    /**
     * 
     * @param haystack Input string
     * @param needle String to be searched from haystack
     * @return If needle can be found among haystack, the first index.
     *         -1 otherwise.
     */
    public int strStr(String haystack, String needle) {
        
        for (int i = 0; i + needle.length() <= haystack.length(); ++i) {
            
            // Check if needle occurs in index i
            boolean isSame = true;
            for (int j = 0; j < needle.length(); ++j) {
                if (needle.charAt(j) != haystack.charAt(i + j)) {
                    isSame = false;
                    break;
                } 
            }
            
            // If needle is found, return the first index
            if (isSame) {
                return i;
            }
        }
        
        return -1;
    }
}
