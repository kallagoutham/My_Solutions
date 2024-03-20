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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode* head= list1;
        b=b-a;
        while(a>1){
            list1=list1->next;
            a--;
        }
        ListNode* tmp=list1;
        while(b>=0){
            list1=list1->next;
            b--;
        }
        tmp->next=list2;
        while(tmp->next != nullptr){
            tmp=tmp->next;
        }
        tmp->next=list1->next;
        return head;
    }
};
