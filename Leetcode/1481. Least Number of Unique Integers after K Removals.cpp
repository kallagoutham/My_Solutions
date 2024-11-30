class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        map<int,int> m;
        int res;
        priority_queue <int, vector<int>, greater<int>> pq;
        for(int i=0;i<arr.size();i++){
            m[arr[i]]++;
        }
        for(auto i=m.begin();i!=m.end();i++){
            pq.push(i->second);
        }
        while(pq.top()<=k){
            k-=pq.top();
            pq.pop();
        }
        return pq.size();
    }
};
