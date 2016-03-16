package leetcode;

public class Solution_0025 {
    
    public class ListNode {
        int val;
        ListNode next;
        ListNode(int x) { val = x; }
    }
    
    /**
     * 
     * @param list List of integers
     * @param k 
     * @return List of integers where 1st k integers, 2nd k integers, 3rd k integers, ...
     *          are reversed
     */
    public ListNode reverseKGroup(ListNode list, int k) {
        
        if (k == 1) {
            return list;
        }
        
        // Insert dummy integer
        ListNode head = new ListNode(-1);
        head.next = list;
        
        ListNode ptr = head;
        
        while (true) {
            
            ListNode next = ptr;
            
            // Check if k integers are remaining
            for (int i = 0; i < k; ++i) {
                next = next.next;
                
                // Less than k integers are remaining, then exit
                if (next == null) {
                    return head.next;
                }
            }
            
            // Reorder nodes
            // Before:
            // (ptr) -> (0) -> (1) -> (2) -> ... -> (k - 2) -> (k - 1) -> (k)
            // After:
            // (ptr) -> (k - 1) -> (k - 2) -> ... -> (2) -> (1) -> (0) -> (k)
            
            // Reverse (0) ... (k - 1)
            // 
            // Step1:
            //   ptr -> 0 -> 1 -> 2 -> 3 -> ... -> (k - 1)
            // Step2:
            //   ptr -> 0 <- 1    2 -> 3 -> ... -> (k - 1)
            // Step3:
            //   ptr -> 0 <- 1 <- 2    3 -> ... -> (k - 1)
            // Step4:
            //   ptr -> 0 <- 1 <- 2 <- 3    ... -> (k - 1)
            //
            // Step k - 1:
            //   ptr -> 0 <- 1 <- 2 <- 3 <- ... <- (k - 1)
            ListNode fst = ptr.next;
            ListNode A = ptr.next;
            ListNode B = ptr.next.next;
            for (int i = 0; i + 1 < k; ++i) {
                ListNode nextB = B.next;
                
                B.next = A;
                
                A = B;
                B = nextB;
            }
            
            // Before:
            //   ptr -> 0 <- 1 <- 2 <- 3 <- ... <- (k - 1)
            // After:
            //   ptr -> (k - 1) -> ... -> 3 -> 2 -> 1 -> 0
            ptr.next.next = B;
            ptr.next = A;
            
            // Move to next Group
            ptr = fst;
        }
    }
}
