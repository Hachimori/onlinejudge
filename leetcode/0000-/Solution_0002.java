package leetcode;

public class Solution_0002 {
    
    public class ListNode {
        int val;
        ListNode next;
        ListNode(int x) { val = x; }
    }
    
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        
        int carry = 0;
        ListNode head = new ListNode(0);
        ListNode tail = head;
        
        while (true) {
            int toAdd = 0;
            toAdd += carry;
            toAdd += l1 != null ? l1.val : 0;
            toAdd += l2 != null ? l2.val : 0;
            
            tail.val = toAdd % 10;
            
            carry = toAdd / 10;
            
            if (l1 != null) l1 = l1.next;
            if (l2 != null) l2 = l2.next;
            
            if (carry == 0 && l1 == null && l2 == null) {
                break;
            }
            
            tail.next = new ListNode(0);
            tail = tail.next;
        }
        
        return head;
    }
}
