package leetcode;

import java.util.PriorityQueue;

/**
 * Problem:
 *   https://leetcode.com/problems/merge-k-sorted-lists/
 * 
 * @author Ben Hachimori
 *
 */
public class Solution_0023 {
    
    /** Pair of value and index among lists[] **/
    private class ValueIndex implements Comparable<ValueIndex> {
        public int val;
        public int idx;
        
        public ValueIndex(int val, int idx) {
            this.val = val;
            this.idx = idx;
        }
        
        @Override
        public int compareTo(ValueIndex o) {
            return val - o.val;
        }
    }
    
    /**
     * 
     * @param lists Array of List of integers
     * @return 
     */
    public ListNode mergeKLists(ListNode[] lists) {
        
        // Store all of value into priority queue
        PriorityQueue<ValueIndex> Q = new PriorityQueue<ValueIndex>();
        for (int i = 0; i < lists.length; ++i) {
            if (lists[i] != null) {
                Q.add(new ValueIndex(lists[i].val, i));
            }
        }
        
        ListNode head = null;
        ListNode tail = null;
        
        while (!Q.isEmpty()) {
            
            // Extract smallest value among lists[]
            ValueIndex vi = Q.poll();
            
            // Push smallest value
            int toAdd = vi.val;
            if (head == null) {
                head = new ListNode(toAdd);
                tail = head;
            }
            else {
                tail.next = new ListNode(toAdd);
                tail = tail.next;
            }
            
            // Extracted lists[index] will proceeds to next node
            int index = vi.idx;
            lists[index] = lists[index].next;
            
            // Push lists[index].val to the priority queue
            if (lists[index] != null) {
                Q.add(new ValueIndex(lists[index].val, index));
            }
        }
        
        return head;
    }
}
