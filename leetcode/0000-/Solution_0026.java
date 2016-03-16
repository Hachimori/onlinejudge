package leetcode;

/**
 * Problem:
 *   https://leetcode.com/problems/remove-duplicates-from-sorted-array/
 * 
 * @author Ben Hachimori
 *
 */
public class Solution_0026 {
    
    /**
     * 
     * @param nums Sorted array of integers
     * @return The number of unique elements
     */
    public int removeDuplicates(int[] nums) {
        
        int cnt = 0;
        for (int i = 0; i < nums.length; ++i) {
            if (cnt == 0 || nums[cnt - 1] != nums[i]) {
                nums[cnt++] = nums[i];
            }
        }
        
        return cnt;
    }
}
