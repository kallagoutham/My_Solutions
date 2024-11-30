class Solution {
public:
    bool isSubstringPresent(string s) {
        set<string> st;
        int n=s.size();
        for(int i=0;i<n-1;i++){
            string t=s.substr(i,2);
            st.insert(t);
        }
        reverse(s.begin(),s.end());
        for(int i=0;i<n-1;i++){
            string t=s.substr(i,2);
            if(st.find(t)!=st.end()){return true;}
        }
        return false;
    }
};
