package leetcode;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashSet;
import java.util.List;
import java.util.Set;

/**
 * Problem:
 *   https://leetcode.com/problems/combination-sum-ii/
 * 
 * @author Ben Hachimori
 *
 */
public class Solution_0040 {
    
    /**
     * 
     * @param candidates Array of integers (Can be used only once)
     * @param target Candidate number 
     * @return The list of integers which sum to target
     */
    public List<List<Integer>> combinationSum2(int[] candidates, int target) {
        
        Arrays.sort(candidates);
        
        Set<List<Integer>> ret = new HashSet<List<Integer>>();
        
        // Initially, start from sum = 0 and empty array
        List<State> curr = new ArrayList<State>();
        curr.add(new State(0, new ArrayList<Integer>()));
        
        // Add numbers in ascending order
        for (int num : candidates) {
            
            // Add num to current state
            for (int i = curr.size() - 1; i >= 0; --i) {
                
                State toPush = new State(curr.get(i));
                
                // Add num to sum exceeds
                if (toPush.sum + num <= target) {
                    toPush.sum += num;
                    toPush.array.add(num);
                    
                    // target value is obtained
                    if (toPush.sum == target) {
                        ret.add(toPush.array);
                    }
                    // lower than target value
                    else {
                        curr.add(new State(toPush));
                    }
                }
            }
        }
        
        return (new ArrayList<List<Integer>>(){{addAll(ret);}});
    }
    
    private class State {
        
        /** Current sum **/
        int sum;
        
        /** Current numbers **/
        List<Integer> array;
        
        State(int sum, List<Integer> array) {
            this.sum = sum;
            this.array = array;
        }
        
        State(State state) {
            this.sum = state.sum;
            this.array = new ArrayList<Integer>(state.array);
        }
    }
}
