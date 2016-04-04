package leetcode;

/**
 * Problem:
 *   https://leetcode.com/problems/multiply-strings/
 * 
 * @author Ben Hachimori
 *
 */
public class Solution_0043 {
    
    /**
     * 
     * @param num1 String representation of input number
     * @param num2 String representation of input number
     * @return String representation of num1 * num2
     */
    public String multiply(String num1, String num2) {
        
        int[] result = new int[num1.length() + num2.length()];
        
        for (int i = 0; i < num1.length(); ++i) {
            int v1 = num1.charAt(num1.length() - 1 - i) - '0';
            for (int j = 0; j < num2.length(); ++j) {
                int v2 = num2.charAt(num2.length() - 1 - j) - '0';
                result[i + j] += v1 * v2;
                result[i + j + 1] += result[i + j] / 10;
                result[i + j] %= 10;
            }
        }
        
        
        StringBuilder sb = new StringBuilder();
        
        int idx = result.length - 1;
        while (idx >= 0 && result[idx] == 0) {
            --idx;
        }
        
        while (idx >= 0) {
            sb.append((char)(result[idx] + '0'));
            --idx;
        }
        
        return sb.length() == 0 ? "0" : sb.toString();
    }
}
