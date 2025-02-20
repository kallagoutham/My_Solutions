class Solution {
public:
    bool isPalindrome(string& s) {
        int l=0,r=s.size()-1;
        while (l < r) {
            if (s[l++] != s[r--]) {
                return false;
            }
        }
        return true;
    }
    vector<vector<string>> res;
    void backtrack(string s,vector<string>& temp,int index){
        if(index==s.size()){
            res.push_back(temp);
            return;
        }
        string t="";
        for(int i=index;i<s.size();i++){
            t+=s[i];
            if(isPalindrome(t)){
                temp.push_back(t);
                backtrack(s,temp,i+1);
                temp.pop_back();
            }
        }
        return;
    }
    vector<vector<string>> partition(string s) {
        vector<string> temp;
        backtrack(s,temp,0);
        return res;
    }
};
