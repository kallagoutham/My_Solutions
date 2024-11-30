/************************************Using Map**************************************************/
class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        unordered_map<int,int> m;
        for(int i=0;i<nums.size();i++){
            if(++m[nums[i]] == nums.size()/2){
                return nums[i];
            }
        }
        return 0;
    }
};


/************************************Using Set**************************************************/
class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        set<int> s;
        for(int i=0;i<nums.size();i++){
            if(s.count(nums[i])==0){ s.insert(nums[i]) ;}else{ return nums[i];}
        }
        return 0;
    }
};
