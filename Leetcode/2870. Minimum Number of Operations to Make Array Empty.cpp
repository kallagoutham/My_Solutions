class Solution {
public:
    int minOperations(vector<int>& nums) {
        unordered_map<int,int> m;
        int res=0;
        for(int i=0;i<nums.size();i++){
            m[nums[i]]++;
        }
        //any how we can make any number with 2,3 addition and only number we cannot form is 1
        //if the number divisible by 3 just do that division
        //if remainder is 1 or two in both cases you will get the best case of floor(number/3) + 1       check with 14,19,10
        for(auto i=m.begin();i!=m.end();i++){
            if(i->second == 1){return -1;}
            (i->second % 3 == 0)?res+=i->second / 3:res+=(i->second/3)+1;
        }
        return res;
    }
};
