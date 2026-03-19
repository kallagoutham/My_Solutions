class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode *h1 = nullptr, *t1 = nullptr;
        ListNode *h2 = nullptr, *t2 = nullptr;

        while (head) {
            ListNode* nextNode = head->next;
            head->next = nullptr;

            if (head->val < x) {
                if (!h1) {
                    h1 = t1 = head;
                } else {
                    t1->next = head;
                    t1 = t1->next;
                }
            } else {
                if (!h2) {
                    h2 = t2 = head;
                } else {
                    t2->next = head;
                    t2 = t2->next;
                }
            }

            head = nextNode;
        }

        if (!h1) return h2; 
        t1->next = h2;
        return h1;
    }
};
