package leetcode;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

/**
 * Problem:
 *   https://leetcode.com/problems/4sum/
 * 
 * @author Ben Hachimori
 *
 */
public class Solution_0018 {
    
    /**
     * 
     * @param nums List of input integers
     * @param target Input integer
     * @return List of four integers (a_1, b_1, c_1, d_1), (a_2, b_2, c_2, d_2), ...
     *         where the equation a_n + b_n + c_n + d_n = target holds
     * @return
     */
    public List<List<Integer>> fourSum(int[] nums, int target) {
        
        Arrays.sort(nums);
        
        Map<Integer, List<List<Integer>>> sum2pair = new HashMap<Integer, List<List<Integer>>>();
        
        // pick a
        for (int i = 0; i < nums.length; ++i) {
            
            // skip the same number to avoid duplicate
            if (i - 1 >= 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            
            // pick b
            for (int j = i + 1; j < nums.length; ++j) {
                
                // skip the same number to avoid duplicate
                if (j - 1 >= i + 1 && nums[j] == nums[j - 1]) {
                    continue;
                }
                
                int sum = nums[i] + nums[j];
                if (!sum2pair.containsKey(sum)) {
                    sum2pair.put(sum, new ArrayList<List<Integer>>());
                }
                
                // store (a + b) into map
                sum2pair.get(sum).add(Arrays.asList(i, j));
            }
        }
        
        List<List<Integer>> ans = new ArrayList<List<Integer>>();
        
        // pick d
        for (int i = nums.length - 1; i >= 0; --i) {
            
            // skip the same number to avoid duplicate
            if (i + 1 < nums.length && nums[i] == nums[i + 1]) {
                continue;
            }
            
            // pick c
            for (int j = i - 1; j >= 0; --j) {
                
                // skip the same number to avoid duplicate
                if (j + 1 <= i - 1 && nums[j] == nums[j + 1]) {
                    continue;
                }
                
                int sum = nums[j] + nums[i];
                
                if (!sum2pair.containsKey(target - sum)) {
                    continue;
                }
                
                // pick (a, b)
                for (List<Integer> abPair : sum2pair.get(target - sum)) {
                    
                    // store as answer
                    if (abPair.get(1) < j) {
                        ans.add(Arrays.asList(nums[abPair.get(0)], nums[abPair.get(1)], nums[j], nums[i]));
                    }
                }
            }
        }
        
        return ans;
    }
}
