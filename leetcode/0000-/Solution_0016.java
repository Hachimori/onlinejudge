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
        
        Set<Integer> aSet = new HashSet<Integer>();
        
        int ans = Integer.MAX_VALUE / 2;
        
        // pick a
        for (int i = 0; i < nums.length; ++i) {
            int a = nums[i];
            if (aSet.contains(a)) {
                continue;
            }
            aSet.add(a);
            
            // pick b
            Set<Integer> bSet = new HashSet<Integer>();
            for (int j = i + 1; j < nums.length; ++j) {
                
                int b = nums[j];
                if (bSet.contains(b)) {
                    continue;
                }
                bSet.add(b);
                
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
