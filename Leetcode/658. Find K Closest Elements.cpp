class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        priority_queue<pair<int,int>> pq;
        vector<int> res;
        for(int i=0;i<arr.size();i++){
            pq.push(make_pair(abs(arr[i]-x),arr[i]));
            if(pq.size()>k){
                pq.pop();
            }
        }
        while(!pq.empty()){
            pair<int,int> temp=pq.top();
            res.push_back(temp.second);
            pq.pop();
        }
        sort(res.begin(),res.end());
        return res;
    }
};
