/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode deleteMiddle(ListNode head) {
        ListNode fast = head;
        ListNode slow = head;
        ListNode prv = head;

        if(head.next == null) return null;

        while(fast.next != null && fast.next.next != null){
            fast = fast.next.next;
            prv = slow;
            slow = slow.next;
        }

        if(fast.next != null){
            slow.next = slow.next.next;
        }else{
            prv.next = slow.next;
        }
        return head; 
    }
}