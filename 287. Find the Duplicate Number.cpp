/************************************************* Using Count Array **************************************************/
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        vector<int> v(100001,0);
        for(int i:nums){
            v[i]++;   
        }
        for(int i=1;i<100001;i++){
            if(v[i]>1){return i;}
        }
        return 1;
    }
};

/************************************************* Using Map **************************************************/

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_map<int,int> s;
        for(int i:nums){
            if(s.find(i)==s.end()){
                s[i]++;
            }else{
                return i;
            }
        }
        return 1;
    }
};
