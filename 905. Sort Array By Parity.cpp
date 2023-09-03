class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int n=nums.size();
        int i=0,j=n-1;

        while(i<j){
            while((nums[i]&1)==0 && i<j){i++;}
            while((nums[j]&1)==1 && j>i){j--;}
            if(i<j){
                nums[i]=nums[i]+nums[j];
                nums[j]=nums[i]-nums[j];
                nums[i]=nums[i]-nums[j];
            }
        }
        return nums;
    }
};
------------------------------------------------------------------------------------------------
class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        unordered_map<int,vector<int>> map;   
        for(auto i:nums){
            map[i&1].push_back(i);
        }
        if(map.find(1)==map.end()){
            return map[0];
        }
        if(map.find(0)==map.end()){
            return map[1];
        }
        map[0].insert(map[0].end(),map[1].begin(),map[1].end());    //insert at the map[0].end() from map[1].begin() to map[1].end()
        return map[0];
    }
};
