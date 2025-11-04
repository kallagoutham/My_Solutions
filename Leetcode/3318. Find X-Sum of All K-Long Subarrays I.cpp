class Solution {
public:
    struct comp{
    bool operator()(pair<int,int> &a,pair<int,int> &b){
        if(a.second != b.second){
            return a.second < b.second;
        }
        return a.first < b.first;
    }};
    vector<int> findXSum(vector<int>& nums, int k, int x) {
        vector<int> res;
        int n=nums.size(),j=0;
        unordered_map<int,int> m;
        for(int i=0;i+k<=n;i++){
            while(j<k+i){
                m[nums[j++]]++;
            }
            priority_queue<pair<int,int>,vector<pair<int,int>>,comp> pq(m.begin(),m.end());
            int s=0,temp=x;
            while(!pq.empty() && temp--){
                s+=(pq.top().first * pq.top().second);
                pq.pop();
            }
            res.push_back(s);
            m[nums[i]]--;
        }
        return res;
    }
};
