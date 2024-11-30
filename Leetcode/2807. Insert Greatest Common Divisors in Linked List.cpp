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
    int gcd(int a,int b){
        if (a<b) {
            swap(a,b);
        }
        while (b!=0) {
            int temp=b;
            b=a%b;
            a=temp;
        }
        return a;
    }
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        if(head->next==nullptr){return head;}
        ListNode* thead=head;
        ListNode* nextNode=head->next;
        while(nextNode){
            ListNode* temp=new ListNode(gcd(thead->val,nextNode->val),nextNode);
            thead->next=temp;
            thead=nextNode;
            nextNode=nextNode->next;
        }
        return head;
    }
};
