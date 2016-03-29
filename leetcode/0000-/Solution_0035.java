package leetcode;

/**
 * Problem:
 *   https://leetcode.com/problems/search-insert-position/
 * 
 * @author Ben Hachimori
 *
 */
public class Solution_0035 {
    
    /**
     * 
     * @param nums Sorted array of integers
     * @param target
     * @return The index if the target is found.
     *         Otherwise, the index to be inserted where the array remains sorted after target's insertion.
     */
    public int searchInsert(int[] nums, int target) {
        return lowerBound(nums, target);
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
