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
    ListNode* reverseList(ListNode* h) {
        ListNode* p=nullptr;
        ListNode* t;
        while(h!=nullptr){
            t=h->next;
            h->next=p;
            p=h;h=t;
        }
        return p;
    }
};
