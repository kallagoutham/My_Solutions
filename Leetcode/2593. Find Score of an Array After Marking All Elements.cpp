class Solution {
public:
    long long findScore(vector<int>& nums) {
        int n=nums.size();
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        for(int i=0;i<n;i++){
            pq.push(make_pair(nums[i],i));
        }
        set<int> s;
        long long res=0;
        while(!pq.empty()){
            pair<int,int> p = pq.top();
            pq.pop();
            if(s.count(p.second)!=1){
                res+=p.first;
                if(p.second>=0 && p.second<n){
                    s.insert(p.second);
                }
                if(p.second+1>=0 && p.second+1<n){
                    s.insert(p.second+1);
                }
                if(p.second-1>=0 && p.second-1<n){
                    s.insert(p.second-1);
                }
            }
        }
        return res;
        
    }
};
