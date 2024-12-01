class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        unordered_map<int,int> m;
        for(int i:arr){
            if(m[i*2]!=0){return true;}
            if(!(i&1)){
                if(m[i/2]!=0){return true;}
            }
            m[i]++;
        }
        return false;
    }
};
