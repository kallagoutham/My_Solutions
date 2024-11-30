class Solution {
public:
    string reverseParentheses(string s) {
        stack<int> st;
        for(int i=0;i<s.size();i++){
            if(s[i]=='('){
                st.push(i);
            }else if (s[i]==')'){
                int t=st.top();
                reverse(s.begin()+t,s.begin()+i);
                st.pop();
            }else{
                continue;
            }
        }
        string res;
        for(int i=0;i<s.size();i++){
            if(s[i]=='(' || s[i]==')'){
                continue;
            }else{
                res.push_back(s[i]);
            }
        }
        return res;
    }
};
