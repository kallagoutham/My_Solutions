class Solution {
public:
    int minOperations(vector<int>& n, int k) {
        int res = 0;
        priority_queue<long, vector<long>, greater<long>> pq;
        for(int i : n) {
            pq.push(static_cast<long>(i));
        }
        while(pq.top() < k) {
            res++;
            long ft = pq.top(); 
            pq.pop();
            long st = pq.top(); 
            pq.pop();
            long temp = static_cast<long>(min(ft, st)) * 2 + max(ft, st);
            pq.push(temp);
        }
        return res;
    }
};
