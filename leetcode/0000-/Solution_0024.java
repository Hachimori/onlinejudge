package leetcode;


/**
 * Problem:
 *   https://leetcode.com/problems/swap-nodes-in-pairs/
 * 
 * @author Ben Hachimori
 *
 */
public class Solution_0024 {
    
    /**
     * 
     * @param list List of input integers
     * @return List of integers where every two nodes are swapped
     */
    public ListNode swapPairs(ListNode list) {
        
        // Insert dummy node
        ListNode head = new ListNode(-1);
        head.next = list;
        
        ListNode pt = head;
        
        while (true) {
            if (pt == null || pt.next == null || pt.next.next == null) {
                break;
            }
            
            ListNode A = pt;
            ListNode B = pt.next;
            ListNode C = pt.next.next;
            ListNode D = pt.next.next.next;
            
            // Reorder the nodes
            //
            // Before:
            //    A -> B -> C -> D
            //
            // After:
            //    A -> C -> B -> D
            A.next = C;
            B.next = D;
            C.next = B;
            
            // Move forward
            pt = B;
        }
        
        return head.next;
    }
}
