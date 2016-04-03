package leetcode;

/**
 * Problem:
 *   https://leetcode.com/problems/first-missing-positive/
 * 
 * @author Ben Hachimori
 *
 */
public class Solution_0041 {
    
    /**
     * 
     * @param nums Input of integer array
     * @return The first missing positive integer
     */
    public int firstMissingPositive(int[] nums) {
        
        // Make it 0-origin index
        for (int i = 0; i < nums.length; ++i) {
            --nums[i];
        }
        
        for (int i = 0; i < nums.length; ++i) {
            if (nums[i] < 0) continue;
            
            int value = nums[i];
            while (0 <= value && value < nums.length && nums[value] != value) {
                int nextIdx = nums[value];
                nums[value] = value;
                value = nextIdx;
            }
        }
        
        for (int i = 0; i < nums.length; ++i) {
            if (nums[i] != i) {
                return i + 1;
            }
        }
        return nums.length + 1;
    }
}
