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
    int getDecimalValue(ListNode* head) {
        vector<int> s;
        while(head!=nullptr){
            s.push_back(head->val);
            head=head->next;
        }
        int t=1;
        int res=0;
        for(int i=s.size()-1;i>=0;i--){
            if(s[i]==1){res+=t;}
            t*=2;
        }
        return res;
    }
};
