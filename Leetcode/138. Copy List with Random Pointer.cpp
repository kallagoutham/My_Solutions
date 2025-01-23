/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head==nullptr){
            return nullptr;
        }
        Node* t=head;
        t=t->next;
        Node* th=new Node(head->val);
        Node* p=th;
        unordered_map<Node*,Node*> m;
        m[head]=th;
        //loop for original values
        while(t){
            p->next=new Node(t->val);
            p=p->next;
            m[t]=p;
            t=t->next;
            
        }
        t=head;
        p=th;
        //loop for random values
        while(t){
            p->random=m[t->random];
            t=t->next;
            p=p->next;
        }
        return th;
    }
};
