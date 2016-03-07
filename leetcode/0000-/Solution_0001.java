package leetcode;

import java.util.HashMap;
import java.util.Map;

public class Solution_0001 {
    
    public int[] twoSum(int[] nums, int target) {
        
        Map<Integer, Integer> val2idx = new HashMap<Integer, Integer>() {{
            for (int i = 0; i < nums.length; ++i) {
                put(nums[i], i);
            }
        }};
        
        for (int i = 0; i < nums.length; ++i) {
            if (!val2idx.containsKey(target - nums[i])) {
                continue;
            }
            
            int idx = val2idx.get(target - nums[i]);
            if (idx == i) {
                continue;
            }
            
            return new int[] {Math.min(i, idx), Math.max(i, idx)};
        }
        
        return null;
    }
}
