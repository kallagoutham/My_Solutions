class Solution {
public:
    bool isIsomorphic(string s, string t) {
        map<char,char> m;
        if(s.length()==t.length()){
            int n=s.length();
            set<char> s1,s2;
            for(int i=0;i<n;i++){
                s1.insert(s[i]);
                s2.insert(t[i]);
            }
            if(s1.size()!=s2.size()){
                return false;
            }
            for(int i=0;i<n;i++){
                if(m.find(s[i])!=m.end()){
                    if(t[i]==m[s[i]]){
                        continue;
                    }
                    return false;
                }
                m[s[i]]=t[i];
            }
            return true;
        }
        return false;
    }
};
