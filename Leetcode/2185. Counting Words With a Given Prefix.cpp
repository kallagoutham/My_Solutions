class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int res=0;
        int n=pref.size();
        for(string word:words){
            if(word.substr(0,n) == pref) res++;
        }
        return res;
    }

};
