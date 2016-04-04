package leetcode;

/**
 * Problem:
 *   https://leetcode.com/problems/trapping-rain-water/
 * 
 * @author Ben Hachimori
 *
 */
public class Solution_0042 {
    
    /**
     * 
     * @param height The height of bars
     * @return The amount of water which can be stored within the sequence of bars
     */
    public int trap(int[] height) {
        
        int ans = 0;
        int waterLevel = 0;
        
        for (int L = 0, R = height.length - 1; L <= R; ) {
            
            // We can guarantee that water level will be at least min(height[L], height[R])
            // because all area within [L-R] is surrounded by the bar height[L] and height[R]
            waterLevel = Math.max(waterLevel, Math.min(height[L], height[R]));
            
            // Proceed lower bar first, because higher bar can be used to store more water
            if (height[L] < height[R]) {
                ans += waterLevel - height[L];
                ++L;
            }
            else {
                ans += waterLevel - height[R];
                --R;
            }
        }
        
        return ans;
    }
}
