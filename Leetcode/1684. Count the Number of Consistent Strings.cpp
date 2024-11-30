class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        int res=0;
        for(string s:words){
            bool con=true;
            for(char c:s){
                if(find(allowed.begin(),allowed.end(),c)==allowed.end()){
                    con=false;
                    break;
                }
            }
            if(con){res++;}
        }
        return res;
    }
};
