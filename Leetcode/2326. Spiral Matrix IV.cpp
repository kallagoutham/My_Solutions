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
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>> res(m, vector<int>(n, -1));
        int tb = 0, bb = m, rb = n, lb = 0;
        char dir = 'R';
        
        while (head) {
            if (dir == 'R') {
                for (int i = lb; i < rb; i++) {
                    if (head) {
                        res[tb][i] = head->val;
                        head = head->next;
                    } else {
                        break;
                    }
                }
                dir = 'B';
                tb++;
            } else if (dir == 'L') {
                for (int i = rb - 1; i >= lb; i--) {
                    if (head) {
                        res[bb - 1][i] = head->val;
                        head = head->next;
                    } else {
                        break;
                    }
                }
                dir = 'T';
                bb--;
            } else if (dir == 'T') {
                for (int i = bb - 1; i >= tb; i--) {
                    if (head) {
                        res[i][lb] = head->val;
                        head = head->next;
                    } else {
                        break;
                    }
                }
                dir = 'R';
                lb++;
            } else { 
                for (int i = tb; i < bb; i++) {
                    if (head) {
                        res[i][rb - 1] = head->val;
                        head = head->next;
                    } else {
                        break;
                    }
                }
                dir = 'L';
                rb--;
            }
        }
        return res;
    }
};
