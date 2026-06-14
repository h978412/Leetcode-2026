/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    int pairSum(ListNode* head) {
        ListNode* slow = head; ListNode* fast = head;

        while(fast->next && fast->next->next){
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* newHead = this->reverse(slow->next);

        int sum = 0;
        while(newHead){
            sum = max(sum, (newHead->val + head->val));
            newHead = newHead->next;
            head = head->next;
        }

        return sum;
        
    }

    ListNode* reverse(ListNode* head){
        ListNode* pre = NULL;
        while(head){
            ListNode* temp = head->next;
            head->next = pre;
            pre = head;
            head = temp;
        }
        return pre;
    }
};