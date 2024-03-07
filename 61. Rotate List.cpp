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
    ListNode* rotateRight(ListNode* head, int k) {
        if(k==0){
            return head;
        }
        if(head==nullptr || head->next ==nullptr){
            return head;
        }
        int l=0;
        ListNode* tmp=head;
        while(tmp!=nullptr){
            tmp=tmp->next;
            l++;
        }
        if( k%l == 0){
            return head;
        }
        l= l - k%l;
        tmp=head;
        ListNode* tmp2;
        while(l--){
            if(l==0){
                tmp2=tmp;
            }
            tmp=tmp->next;
        }
        tmp2->next = nullptr;
        tmp2=head;
        head = tmp;
        while(tmp!=nullptr && tmp->next!=nullptr){
            tmp=tmp->next;
        }
        if(tmp!=nullptr){
            tmp->next=tmp2;
        }
        return head;
    }
};
