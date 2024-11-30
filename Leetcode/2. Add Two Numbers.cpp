class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* p=new ListNode(0);
        ListNode* th=p;
        int c=0;
        if(l1==nullptr)
            return l2;
        if(l2==nullptr)
            return l1;
        while(l1!=nullptr && l2!=nullptr){
            ListNode* t=new ListNode(((l1->val)+(l2->val)+c)%10);
            c=((l1->val)+(l2->val)+c)/10;
            l1=l1->next;
            l2=l2->next;
            p->next=t;
            p=t;
        }
        while(l2!=nullptr){
            ListNode* t=new ListNode(((l2->val)+c)%10);
            c=((l2->val)+c)/10;
            l2=l2->next;
            p->next=t;
            p=t;
        }
        while(l1!=nullptr){
            ListNode* t=new ListNode(((l1->val)+c)%10);
            c=((l1->val)+c)/10;
            l1=l1->next;
            p->next=t;
            p=t;
        }
        if(c!=0){
             ListNode* t=new ListNode(c);
            p->next=t;
            p=t;
        }
        return th->next;
    }
};
