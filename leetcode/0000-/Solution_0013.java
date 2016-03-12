package leetcode;

/**
 * Problem:
 *   https://leetcode.com/problems/roman-to-integer/
 * 
 * @author Ben Hachimori
 *
 */
public class Solution_0013 {
    
    /**
     * 
     * 
     * @param s Input string (Roman numeric representation)
     * @return integer representation of input string
     */
    public int romanToInt(String s) {
        
        int ans = 0;
        
        // 1000
        for (int num = 3; num >= 0; --num) {
            String roman = getRoman(num, 'M', '-', '-');
            if (s.startsWith(roman)) {
                s = s.substring(roman.length());
                ans += 1000 * num;
                break;
            }
        }
        
        // 100, 10, 1
        for (int idx = 0; idx < 3; ++idx) {
            final int[]  mul  = {100,  10,   1};
            final char[] one  = {'C', 'X', 'I'};
            final char[] five = {'D', 'L', 'V'};
            final char[] ten  = {'M', 'C', 'X'};
            
            for (int num = 9; num >= 0; --num) {
                String roman = getRoman(num, one[idx], five[idx], ten[idx]);
                if (s.startsWith(roman)) {
                    s = s.substring(roman.length());
                    ans += mul[idx] * num;
                    break;
                }
            }
        }
        
        return ans;
    }
    
    /**
     * Converts integer value 0-9 to Roman numeric representation
     * 
     * @param value 0-9
     * @param one Roman Symbol representing one unit
     * @param five Roman Symbol representing five unit
     * @param ten Roman Symbol representing ten unit
     * @return Roman numeric representation for integer value 0-9
     */
    private String getRoman(int value, char one, char five, char ten) {
        
        StringBuilder sb = new StringBuilder();
        
        if (value <= 3) {
            for (int i = 0; i < value; ++i) {
                sb.append(one);
            }
        }
        else if (value == 4) {
            sb.append(one);
            sb.append(five);
        }
        else if (value <= 8) {
            sb.append(five);
            for (int i = 0 ; i < value - 5; ++i) {
                sb.append(one);
            }
        }
        else {
            sb.append(one);
            sb.append(ten);
        }
        
        return sb.toString();
    }
}
