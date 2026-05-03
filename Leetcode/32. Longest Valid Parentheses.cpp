class Solution {
public:
    int longestValidParentheses(string s) {
        int res = 0;
        stack<int> st;
        // we have to push -1 initially
        st.push(-1);
        for(int i=0;i<s.size();i++){
            if(s[i]=='('){
                st.push(i);
            }else{
                st.pop(); // pop the index valid till this point
                if(st.empty()){
                    st.push(i); // last invalid point
                }else{
                    res = max(res,i-st.top()); // compute the length
                }
            }
        }
        return res;
    }
};
