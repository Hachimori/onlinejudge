package leetcode;

/**
 * Problem:
 *   https://leetcode.com/problems/merge-two-sorted-lists/
 * 
 * @author Ben Hachimori
 *
 */
public class Solution_0021 {
    
    /**
     * 
     * @param l1 List of sorted integer values
     * @param l2 List of sorted integer values
     * @return List of sorted integer from l1 and l2
     */
    public ListNode mergeTwoLists(ListNode l1, ListNode l2) {
        
        if (l1 == null) return l2;
        if (l2 == null) return l1;
        
        ListNode head = null;
        ListNode tail = null;
        
        while (l1 != null || l2 != null) {
            
            int toAdd;
            
            // Compare l1 and l2 and choose smaller value
            if (l1 != null && (l2 == null || l1.val < l2.val)) {
                toAdd = l1.val;
                l1 = l1.next;
            }
            else {
                toAdd = l2.val;
                l2 = l2.next;
            }
            
            // Add value to the list
            if (head == null) {
                head = new ListNode(toAdd);
                tail = head;
            }
            else {
                tail.next = new ListNode(toAdd);
                tail = tail.next;
            }
        }
        
        return head;
    }
}
