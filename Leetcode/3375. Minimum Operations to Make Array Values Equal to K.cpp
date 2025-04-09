class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        unordered_map<int,int> f;
        int mini=INT_MAX;
        for(int i:nums){
            f[i]++;
            mini=min(mini,i);
        }
        cout<<mini<<endl;
        if(mini<k){
            return -1;
        }
        if(k<mini){
            return f.size();
        }
        return f.size()-1;
    }
};
