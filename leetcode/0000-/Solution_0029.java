package leetcode;

/**
 * Problem:
 *   https://leetcode.com/problems/divide-two-integers/
 * 
 * @author Ben Hachimori
 *
 */
public class Solution_0029 {
    
    /**
     * 
     * @param dividend The number to be divided
     * @param divisor The divisor for dividend
     * @return The result of dividend / divisor
     */
    public int divide(int dividend, int divisor) {
        return (int) Math.min(mydivide(dividend, divisor), Integer.MAX_VALUE);
    }
    
    /**
     * To avoid overflow, convert to long.
     * 
     * @param dividend The number to be divided
     * @param divisor The divisor for dividend
     * @return The result of dividend / divisor
     */
    private long mydivide(long dividend, long divisor) {
        
        if (dividend < 0) return -mydivide(-dividend, divisor);
        if (divisor < 0) return -mydivide(dividend, -divisor);
        
        long ret = 0;
        
        for (int bit = 31; bit >= 0; --bit) {
            if (dividend >= divisor * (1L << bit)) {
                dividend -= divisor * (1L << bit);
                ret += 1L << bit;
            }
        }
        
        return ret;
    }
}
