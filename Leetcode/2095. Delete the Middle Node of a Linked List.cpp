class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        if (head -> next == nullptr)
            return nullptr;
        int count = 0;
        ListNode *p1 = head, *p2 = head;
        while (p1 != nullptr) {
            count++;
            p1 = p1 -> next;
        }
        int middleIndex = count / 2;
        for (int i = 0; i < middleIndex - 1; ++i)
            p2 = p2 -> next;
        p2 -> next = p2 -> next -> next;
        return head;
    }
};
