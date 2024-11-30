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
    ListNode* doubleIt(ListNode* head) {
        ListNode* revHead = nullptr;
        ListNode* t;
        while(head!=nullptr){
            t = new ListNode(head->val);
            t->next = revHead;
            revHead = t;
            head = head->next;
        }
        int carry = 0,num;
        while(revHead!=nullptr){
            num = (revHead->val) * 2 + carry;
            carry = num/10;
            num = num%10;
            t = new ListNode(num);
            t->next = head;
            head = t;
            revHead = revHead->next;
        }
        while(carry!=0){
            t = new ListNode(carry%10);
            t->next = head;
            head = t;
            carry /= 10;
        }
        return head;
    }
};
