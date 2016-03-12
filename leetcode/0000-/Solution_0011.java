package leetcode;

public class Solution_0011 {
    
    public int maxArea(int[] height) {
        
        int L = 0;
        int R = height.length - 1;
        int maxArea = 0;
        
        while (L < R) {
            maxArea = Math.max(maxArea, (R - L) * Math.min(height[L], height[R]));
            if (height[L] < height[R]) {
                ++L;
            }
            else {
                --R;
            }
        }
        
        return maxArea;
    }
}
