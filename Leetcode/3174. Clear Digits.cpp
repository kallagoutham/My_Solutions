class Solution {
public:
    string clearDigits(string s) {
        stack<char> st;
        for(char ch:s){
            if(ch<'a'){
                if(!st.empty()){
                    st.pop();
                }
            }else{
                st.push(ch);
            }
        }
        string res="";
        while(!st.empty()){
            res+=st.top();
            st.pop();
        }
        reverse(res.begin(),res.end());
        return res;
    }
};
