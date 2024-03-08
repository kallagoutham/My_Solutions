class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        int mx=INT_MIN,res=0;
        unordered_map<int,int> m;
        for(int i:nums){
            m[i]++;
            mx=max(mx,m[i]);
        }
        for(auto i=m.begin();i!=m.end();i++){
            if(i->second==mx){res+=mx;}
        }
        return res;
    }
};
