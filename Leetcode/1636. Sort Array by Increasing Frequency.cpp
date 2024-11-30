class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int,int> m;
        for(int i:nums){
            m[i]++;
        }
        map<int,vector<int>> r;
        for(auto i=m.begin();i!=m.end();i++){
            r[i->second].push_back(i->first);
        }
        nums.clear();
        for(auto i=r.begin();i!=r.end();i++){
            sort(i->second.begin(),i->second.end(),greater<int>());
            for(int j=0;j<i->second.size();j++){
                int t=i->first;
                while(t--){
                    nums.push_back(i->second[j]);
                }
            }
        }
        return nums;
    }
};
