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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        map<int,vector<ListNode*>> m;
        for(int i=0;i<lists.size();i++){
            ListNode* head =lists[i];
            while(head!=nullptr){
                m[head->val].push_back(head);
                head=head->next;
            }
        }
        ListNode* resHead=nullptr;
        ListNode* head=nullptr;
        for(auto i=m.begin();i!=m.end();i++){
            for(auto j=0;j<i->second.size();j++){
                if(resHead==nullptr){
                    resHead=i->second[j];
                    head=i->second[j];
                    head->next=nullptr;
                    continue;
                }
                head->next=i->second[j];
                head=head->next;
                head->next=nullptr;
            }
        }
        return resHead;
    }
};
