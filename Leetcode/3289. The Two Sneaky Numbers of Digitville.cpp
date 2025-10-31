class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        unordered_map<int,int> m;
        vector<int> res;
        for(int num:nums){
            m[num]++;
            if(m[num]==2){res.push_back(num);}
            if(res.size()==2){return res;}
        }
        return res;
    }
};

//--------------------------Solution Using Bitset----------------------------

class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        bitset<100> b;
        vector<int> res;
        for(int i:nums){
            if(!b[i]){
                b.set(i);
            }else{
                res.push_back(i);
            }
        }
        return res;
    }
};
