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
    ListNode* middleNode(ListNode* head) {
        ListNode* fp=head;
        ListNode* sp=head;
        while(fp!=nullptr && fp->next!=nullptr){
            fp=fp->next->next;
            sp=sp->next;
        }
        return sp;
    }
};
