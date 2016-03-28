package leetcode;

import java.util.Arrays;

/**
 * Problem:
 *   https://leetcode.com/problems/search-in-rotated-sorted-array/
 * 
 * @author Ben Hachimori
 *
 */
public class Solution_0033 {
    
    /**
     * 
     * @param nums Rotated sorted array
     * @param target Value to be found
     * @return The index, if target is found among nums, otherwise return -1
     */
    public int search(int[] nums, int target) {
        
        // Perform binarysearch to find out the smallest value among nums
        int L = 0;
        int R = nums.length;
        while (L < R) {
            int mid = (L + R) / 2;
            
            if (nums[0] <= nums[mid]) {
                L = mid + 1;
            }
            else {
                R = mid;
            }
        }
        
        // Search target from nums[0 ... L - 1] (nums[0 ... L - 1] is sorted)
        int idx = Arrays.binarySearch(nums, 0, L, target);
        if (idx >= 0) {
            return idx;
        }
        
        // Search target from nums[L ... nums.length - 1] (nums[L ... nums.length - 1] is sorted)
        idx = Arrays.binarySearch(nums, L, nums.length, target);
        return idx >= 0 ? idx : -1;
    }
}
