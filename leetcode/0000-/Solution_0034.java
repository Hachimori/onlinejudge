package leetcode;

/**
 * Problem:
 *   https://leetcode.com/problems/search-for-a-range/
 * 
 * @author Ben Hachimori
 *
 */
public class Solution_0034 {
    
    /**
     * 
     * @param nums Sorted array of integers
     * @param target
     * @return if target appears among nums,
     *         returns leftmost / rightmost index of nums where target appears
     *         otherwise returns [-1, -1]
     */
    public int[] searchRange(int[] nums, int target) {
        
        // Find the leftmost index among nums, where target appears
        int leftmost = lowerBound(nums, target);
        
        // When target does not appear, return [-1, -1]
        if (leftmost == nums.length || nums[leftmost] != target) {
            return new int[] {-1, -1};
        }
        
        // Find the rightmost index among nums, where target appears
        int rightmost = lowerBound(nums, target + 1) - 1;
        
        return new int[] {leftmost, rightmost};
    }
    
    
    /**
     * Returns the leftmost index among nums, where nums[index] >= target.
     * 
     * @param nums Sorted array of integers
     * @param target
     * @return The leftmost index among nums, where nums[index] >= target.
     *         If all of integers are smaller than target, returns nums.length.
     */
    private int lowerBound(int[] nums, int target) {
        
        int L = 0;
        int R = nums.length;
        
        while (L < R) {
            int mid = (L + R) / 2;
            
            if (nums[mid] < target) {
                L = mid + 1;
            }
            else {
                R = mid;
            }
        }
        
        return L;
    }
}
