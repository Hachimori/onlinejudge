package leetcode;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashSet;
import java.util.List;
import java.util.Set;

/**
 * Problem:
 *   https://leetcode.com/problems/3sum/
 * 
 * @author Ben Hachimori
 *
 */
public class Solution_0016 {
    
    /**
     * 
     * @param nums list of input integers
     * @param target input integer
     * @return sum of three integers from nums
     *         where the sum is closest to the given target
     */
    public int threeSumClosest(int[] nums, int target) {
        
        Arrays.sort(nums);
        
        int ans = Integer.MAX_VALUE / 2;
        
        // pick a
        for (int i = 0; i < nums.length; ++i) {
            
            // skip the same number to avoid duplicate
            if (i - 1 >= 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            
            int a = nums[i];
            
            // pick b
            for (int j = i + 1; j < nums.length; ++j) {
                
                // skip the same number to avoid duplicate
                if (j - 1 >= i + 1 && nums[j] == nums[j - 1]) {
                    continue;
                }
                
                int b = nums[j];
                
                // pick c
                // From the equation a + b + c == target, c = target - a - b
                int toFind = target - a - b;
                
                // binary search c from nums[j+1 ... nums.length-1]
                int idx = Arrays.binarySearch(nums, j + 1, nums.length, toFind);
                
                // c is found
                if (0 <= idx && idx < nums.length) {
                    return target;
                }
                // c is not found
                else {
                    idx = -(idx + 1);
                    
                    if (idx - 1 >= j + 1 && Math.abs(ans - target) > Math.abs(a + b + nums[idx - 1] - target)) {
                        ans = a + b + nums[idx - 1];
                    }
                    
                    if (idx < nums.length && Math.abs(ans - target) > Math.abs(a + b + nums[idx] - target)) {
                        ans = a + b + nums[idx];
                    }
                }
            }
        }
        
        return ans;
    }
}
