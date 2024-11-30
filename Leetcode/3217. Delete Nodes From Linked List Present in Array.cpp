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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_set<int> numSet(nums.begin(), nums.end());
        ListNode* temp=head;
        ListNode* prev=new ListNode(-1,head);
        while(temp!=nullptr){
            if(numSet.find(temp->val)!=numSet.end()){
                if(temp==head){
                    prev->next=head->next;
                    head=head->next;
                }else{
                    prev->next=temp->next;
                }
            }else{
                prev=prev->next;
            }
            temp=temp->next;
        }
        return head;
    }
};
