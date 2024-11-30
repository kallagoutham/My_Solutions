class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> res;
        priority_queue<int> pq;
        unordered_map<int,int> m;
        for(int i:nums){
            m[i]++;
        }
        for(auto i=m.begin();i!=m.end();++i){
            pq.push(i->second);
        }
      
        while(k>0){
            int t=pq.top();
            pq.pop();
            for(auto i=m.begin();i!=m.end();){
                if(i->second==t){
                    res.push_back(i->first);
                   i = m.erase(i);                   
        
                }else{
                    i++;
                }
            }
            k--;
        }
        return res;
    }
};
