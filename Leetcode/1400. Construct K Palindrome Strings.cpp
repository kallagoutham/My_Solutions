class Solution {
public:
    bool canConstruct(string s, int k) {
        vector<int> freq(26,0);
        if(s.size()<k){return false;}
        for(char c:s) freq[c-'a']++;
        for(int i=0;i<26;i++){
            if(freq[i]&1==1){
                if(k>0){
                    k--;
                }else{
                    return false;
                }
            }
        }
        return true;
    }
};
