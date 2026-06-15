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
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        ListNode head = new ListNode();
        ListNode temp = head;
        int carry = 0;

        while(l1!=null || l2!= null){
            System.out.println("here");
            int sum = (l1==null?0:l1.val) + (l2==null?0:l2.val) + carry;
            // head.next.val = sum%10;
            carry = sum/10;
            head.next = new ListNode(sum%10);
            head = head.next;
            if(l1 != null)l1 = l1.next;
            if(l2 != null)l2 = l2.next;
        }
        if(carry != 0) head.next = new ListNode(carry);
        return temp.next;
        
    }
}