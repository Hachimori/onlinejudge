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
public class Solution_0015 {
    
    /**
     * 
     * @param nums list of input integers
     * @return List of three integers (a_1, b_1, c_1), (a_2, b_2, c_2), ...
     *         where the equation a_n + b_n + c_n = 0 holds
     */
    public List<List<Integer>> threeSum(int[] nums) {
        
        Arrays.sort(nums);
        
        Set<Integer> cSet = new HashSet<Integer>() {{
            for (int num : nums) {
                add(num);
            }
        }};
        
        List<List<Integer>> abcList = new ArrayList<List<Integer>>();
        
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
                
                // From the equation a + b + c == 0, c = - a - b
                int target = - nums[i] - nums[j];
                
                if (target < nums[j]) {
                    continue;
                }
                
                if ((target == nums[j] && !(j + 1 < nums.length && nums[j + 1] == target)) || !cSet.contains(target)) {
                    continue;
                }
                
                abcList.add(Arrays.asList(nums[i], nums[j], target));
            }
        }
        
        return abcList;
    }
}
