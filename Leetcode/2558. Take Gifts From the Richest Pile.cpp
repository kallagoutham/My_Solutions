class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        long long res=0;
        priority_queue<int> pq;
        for(int i:gifts){pq.push(i);}
        while(k>0){
            pq.push(int(sqrt(pq.top())));
            pq.pop();
            k--;
        }
        while(!pq.empty()){res+=(pq.top());pq.pop();}
        return res;
    }
};
