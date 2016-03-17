package leetcode;

/**
 * Problem:
 *   https://leetcode.com/problems/remove-element/
 * 
 * @author Ben Hachimori
 *
 */
public class Solution_0027 {
    
    /**
     * 
     * @param nums Array of integers.
     *             The integer which is equal to val should be deleted.
     *             The order of elements can be changed.
     * @param val The number to be deleted from nums
     * @return The number of remaining integers after deletion
     */
    public int removeElement(int[] nums, int val) {
        
        int length = nums.length;
        
        for (int i = 0; i < length; ++i) {
            if (nums[i] == val) {
                nums[i] = nums[length - 1];
                --length;
                --i;
            }
        }
        
        return length;
    }
}
