package leetcode;

/**
 * Problem:
 *   https://leetcode.com/problems/remove-nth-node-from-end-of-list/
 * 
 * @author Ben Hachimori
 *
 */
public class Solution_0019 {
    
    /**
     * 
     * @param head Input linked list
     * @param n n-th node from the end should be deleted
     * @return Head of liked list which n-th node from the end is deleted
     */
    public ListNode removeNthFromEnd(ListNode head, int n) {
        
        ListNode slow = head;
        ListNode fast = head;
        
        for (int i = 0; i < n; ++i) {
            fast = fast.next;
        }
        
        if (fast == null) {
            return head.next;
        }
        
        while (true) {
            if (fast.next == null) {
                slow.next = slow.next.next;
                return head;
            }
            slow = slow.next;
            fast = fast.next;
        }
    }
}
