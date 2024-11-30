class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int tp = k;
        vector<ListNode*> res;
        if (k == 1) {
            res.push_back(head);
            return res;
        }
        int l = 0;
        ListNode* th = head;
        while (th) {
            l++;
            th = th->next;
        }
        if (k > l) {
            res.assign(k, nullptr);
            for (int i = 0; i < l; ++i) {
                res[i] = head;
                if (head) {
                    head = head->next;
                    res[i]->next = nullptr;
                }
            }
            return res;
        }
        int t = l / k;
        int extraNodes = l % k;
        while (tp > 0) {
            ListNode* th = head;
            int fl = t + (extraNodes > 0 ? 1 : 0); 
            while (fl > 1 && head) {
                head = head->next;
                fl--;
            }
            if (head) {
                ListNode* prev = head;
                head = head->next;
                prev->next = nullptr;
            }
            res.push_back(th);
            tp--;
            if (extraNodes > 0) {
                extraNodes--;
            }
        }
        return res;
    }
};
