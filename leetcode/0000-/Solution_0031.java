package leetcode;

import java.util.Arrays;

/**
 * Problem:
 *   https://leetcode.com/problems/next-permutation/
 * 
 * @author Ben Hachimori
 *
 */
public class Soclution_0031 {
    
    /**
     * Rearrange nums as the lexicographically next greater permutation of numbers.
     * 
     * @param nums Input of integers 
     */
    public void nextPermutation(int[] nums) {
        
        for (int idx = nums.length - 1; idx >= 0; --idx) {
            
            // Find the smallest number of integer among nums[idx + 1 ... nums.length - 1]
            // which is greater than nums[idx]
            int minIdx = -1;
            for (int i = idx + 1; i < nums.length; ++i) {
                if (nums[idx] < nums[i] && (minIdx == -1 || nums[minIdx] > nums[i])) {
                    minIdx = i;
                }
            }
            
            if (minIdx != -1) {
                // Swap nums[idx] and nums[minIdx]
                int t = nums[idx];
                nums[idx] = nums[minIdx];
                nums[minIdx] = t;
                
                // Reorder nums[idx + 1 ... nums.length - 1]
                Arrays.sort(nums, idx + 1, nums.length);
                
                return;
            }
        }
        
        // No rearrangement is done, sort numbers
        Arrays.sort(nums);
    }
}
