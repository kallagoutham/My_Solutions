class Solution {
public:
    int minimumLength(string s) {
        unordered_map<char,int> m;
        int res=0;
        for(char c:s) m[c]++;
        for(auto i=m.begin();i!=m.end();i++){
            if(i->second&1){
                res+=1;
            }else{
                res+=2;
            }
        }
        return res;
    }
};
