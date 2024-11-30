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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int l=0;
        ListNode* th=head;
        while(th){
            l++;
            th=th->next;
        }
        if(l==n){
            return head->next;
        }
        l=l-n;
        th=head;
        while(l>1){
            th=th->next;
            l--;
        }
        th->next=th->next->next;
        return head;
    }
};
