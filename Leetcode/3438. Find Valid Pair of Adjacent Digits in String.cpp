class Solution {
public:
    string findValidPair(string s) {
        unordered_map<char,int> m;
        int n=s.size();
        for(int i=0;i<n;i++){
            m[s[i]]++;
        }
        for(int i=0;i<n-1;i++){
            if(s[i]!=s[i+1] && (m[s[i]]==(s[i]-'0')) && (m[s[i+1]]==(s[i+1]-'0'))){
                return s.substr(i,2);
            }
        }
        return "";
    }
};
