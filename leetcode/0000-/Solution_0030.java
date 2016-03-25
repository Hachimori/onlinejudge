package leetcode;

import java.util.ArrayList;
import java.util.List;

/**
 * Problem:
 *   https://leetcode.com/problems/substring-with-concatenation-of-all-words/
 * 
 * @author Ben Hachimori
 *
 */
public class Solution_0030 {
    
    static final int MOD = 1000000007;
    
    /**
     * 
     * @param s 
     * @param words
     * @return The list indexes in s, where all words sequentially appear exactly once
     */
    public List<Integer> findSubstring(String s, String[] words) {
        
        // Calculate hash for words
        long hash = 1;
        for (String word : words) {
            hash *= word.hashCode();
            hash %= MOD;
        }
        
        int nWord = words.length;
        int wordLeng = words[0].length();
        
        List<Integer> ret = new ArrayList<Integer>();
        
        for (int idx = 0; idx + nWord * wordLeng <= s.length(); ++idx) {
            
            // Calculate hash for s[idx ... idx + wordLeng], s[idx + wordLeng ... idx + 2 * wordLeng] and so on.
            long newHash = 1;
            for (int i = 0; i < nWord; ++i) {
                String newWord = s.substring(idx + i * wordLeng, idx + (i + 1) * wordLeng);
                newHash *= newWord.hashCode();
                newHash %= MOD;
            }
            
            // If hash is same, then match
            if (hash == newHash) {
                ret.add(idx);
            }
        }
        
        return ret;
    }
}
