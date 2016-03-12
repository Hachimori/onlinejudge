package leetcode;

/**
 * Problem:
 *   https://leetcode.com/problems/integer-to-roman/
 * 
 * @author Ben Hachimori
 *
 */
public class Solution_0012 {
    
    /**
     * 
     * @param num
     * @return
     */
    public String intToRoman(int num) {
        
        return getRoman(num / 1000 % 10, 'M', '-', '-') +
               getRoman(num / 100  % 10, 'C', 'D', 'M') +
               getRoman(num / 10   % 10, 'X', 'L', 'C') +
               getRoman(num        % 10, 'I', 'V', 'X');
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
