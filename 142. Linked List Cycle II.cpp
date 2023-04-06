/*Intuition :
Use a Floyd's Cycle-Finding algorithm to detect a cycle in a linked list and find the node where the cycle starts.
What is Floyd's Cycle-Finding algorithm ?
It is also called Hare-Tortoise algorithm
The algorithm works by using two pointers, a slow pointer and a fast pointer.
Initially, both pointers are set to the head of the linked list.
The fast pointer moves twice as fast as the slow pointer.
If there is a cycle in the linked list, eventually, the fast pointer will catch up with the slow pointer.
If there is no cycle, the fast pointer will reach the end of the linked list.
Approach :
When the two pointers meet, we know that there is a cycle in the linked list.
We then reset the slow pointer to the head of the linked list and move both pointers at the same pace, one step at a time, until they meet again.
The node where they meet is the starting point of the cycle.
If there is no cycle in the linked list, the algorithm will return null.*/


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* fp=head;
        ListNode* sp=head;
        while(fp!=nullptr && fp->next!=nullptr){
            fp=fp->next->next;
            sp=sp->next;
            if(fp==sp){
                sp=head;
                while(sp!=fp){
                    fp=fp->next;
                    sp=sp->next;
                }
                return sp;
            }
        }
        return nullptr;
    }
};
