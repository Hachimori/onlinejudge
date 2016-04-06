package leetcode;

/**
 * Problem:
 *   https://leetcode.com/problems/wildcard-matching/
 * 
 * @author Ben Hachimori
 *
 */
public class Solution_0044 {
    
    public static void main(String s[]) {
        Solution_0044 solver = new Solution_0044();
        
        System.out.println("aa , a " + solver.isMatch("aa", "a") + (solver.isMatch("aa", "a") == false));
        System.out.println("aa , aa " + solver.isMatch("aa", "aa") + (solver.isMatch("aa", "aa") == true));
        System.out.println("aaa , aa " + solver.isMatch("aaa", "aa") + (solver.isMatch("aaa", "aa") == false));
        System.out.println("aa , * " + solver.isMatch("aa", "*") + (solver.isMatch("aa", "*") == true));
        System.out.println("ab , ?* " + solver.isMatch("ab", "?*") + (solver.isMatch("ab", "?*") == true));
        System.out.println("aab , c*a*b " + solver.isMatch("aab", "c*a*b") + (solver.isMatch("aab", "c*a*b") == true));
        System.out.println("abb , a* " + solver.isMatch("abb", "a*") + (solver.isMatch("abb", "a*") == true));
        System.out.println("hi , *? " + solver.isMatch("hi", "*?") + (solver.isMatch("abb", "a*") == true));
        
    }
    
    /**
     * 
     * @param s String to be matched
     * @param p Pattern. Pattern might include '?' (Matches any single character)
     *          and '*' (Matches any sequence of characters, including empty character)
     * @return
     */
    public boolean isMatch(String s, String p) {
        
        int sIdx = 0;
        int pIdx = 0;
        int sIdxAtLastStar = -1;
        int pIdxAtLastStar = -1;
        
        while (sIdx < s.length()) {
            
            if (pIdx < p.length() && (s.charAt(sIdx) == p.charAt(pIdx) || p.charAt(pIdx) == '?')) {
                ++sIdx;
                ++pIdx;
            }
            else if (pIdx < p.length() && p.charAt(pIdx) == '*') {
                sIdxAtLastStar = sIdx;
                pIdxAtLastStar = pIdx;
                
                ++pIdx;
            }
            else if (sIdxAtLastStar != -1) {
                sIdx = ++sIdxAtLastStar;
                pIdx = pIdxAtLastStar + 1;
            }
            else {
                return false;
            }
        }
        
        while (pIdx < p.length() && p.charAt(pIdx) == '*') ++pIdx;
        return pIdx == p.length();
    }
}
