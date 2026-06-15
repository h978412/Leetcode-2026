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
        return this.sum(l1,l2,0);
    }

    private ListNode sum(ListNode l1, ListNode l2, int carry){
        if(l1==null && l2==null) return carry==0?null:new ListNode(carry);

        int sum = (l1==null?0:l1.val) + (l2==null?0:l2.val) + carry;
        ListNode node = new ListNode(sum%10);
        l1 = l1==null?l1:l1.next;
        l2 = l2==null?l2:l2.next;
        node.next = this.sum(l1,l2,sum/10);
        return node;
    }
}